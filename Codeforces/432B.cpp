#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

struct RangeAdd{
    using T = long long;
    T operator()(const T &a, const T &b){return a+b;};
    static constexpr T id(){return T(0);};
};

struct RangeSum{
    using T = long long;
    T operator()(const T &a, const T &b){return a+b;}
    static constexpr T id(){return T(0);};
};

struct Add_Sum{
    using V = RangeSum;
    using A = RangeAdd;
    V::T operator()(const V::T &a, const A::T &b, const int &h){return a+(b<<h);};
};
template<typename M>
struct LazySegmentTree{
    using Val = typename M::V::T;
    using Del = typename M::A::T;
    typename M::V calc;
    typename M::A composite;
    M act;
    vector<Val> val;
    vector<Del> delay;

    int n,height;
    explicit LazySegmentTree(int size) : n(1),height(0){
        while(n<size){n<<=1;++height;}
        val=vector<Val>(n<<1,calc.id());
        delay=vector<Del>(n<<1,composite.id());
    }
    explicit LazySegmentTree(vector<Val> &v):n(1),height(0){
        while(n < v.size()) {n <<=1;++height;}
        val = vector<Val> (n<<1,calc.id());
        delay=vector<Del>(n<<1,composite.id());
        copy(v.begin(),v.end(),val.begin()+n);
        for(int i=n-1; i>0; --i){val[i]=calc(val[i*2],val[i*2+1]);}
    }
    void propagate(int k,int h){
        val[k]=act(val[k],delay[k],h);
        if(h>0){
            delay[2*k]=composite(delay[2*k], delay[k]);
            delay[2*k+1]=composite(delay[2*k+1], delay[k]);
        }
        delay[k]=composite.id();
    }
    inline void update(int l, int r, Del v){update(l,r,v,1,0,n,height);}
    void update(int l, int r, Del v, int k, int a, int b, int h){
        if(l<=a && b<=r){
            delay[k]=composite(delay[k],v);
            propagate(k,h);
            return;
        }
        propagate(k,h);
        if(b<=l || r<=a){return ;}//
        update(l,r,v,2*k,a,(a+b)/2,h-1);
        update(l,r,v,2*k+1,(a+b)/2,b,h-1);
        val[k]=calc(val[2*k],val[2*k+1]);
    }
    inline Val query(int l,int r){return query(l,r,1,0,n,height);}
    Val query(int l, int r, int k, int a, int b, int h){
        if(b<=l || r<=a){return calc.id();}//
        propagate(k,h);
        if(l<=a && b<=r){
            return val[k];
        }
        Val vall=query(l,r,2*k,a,(a+b)/2,h-1);
        Val valr=query(l,r,2*k+1,(a+b)/2,b,h-1);
        return calc(vall,valr);
    }
};
struct Problem{
    LL n,x,y,ub;
    vector<LL> a,cost;
    vector<LL> primes;
    Problem(LL n):n(n),ub(1e6),a(n),cost(ub+1){};
    void sieve (LL n,vector<LL> &p){
        vector<char> isprime(n+1,1);
        //int cnt=0;
        isprime[0]=isprime[1]=0;
        for(LL i=2; i<=n; i++){
            if(isprime[i]){
                primes.push_back(i);
                //++cnt;
                for(LL j=i*i; j<=n; j+=i) isprime[j]=0;
            }
        }
        return;
    }
    void solve(){
        int bd=60;
        sieve(ub,primes);
        vector<LL> ans((int)primes.size());
        cin >> x >> y;
        for(int i=0; i<n; ++i){
            cin >> a[i];
            for(int j=0; j<bd; ++j){
                ans[j]+=min(((primes[j]-(a[i]%primes[j]))%primes[j])*y,x);
            }
        }
        sort(a.begin(),a.end());
        if(a.back()==1){
            cout << y+min(x,y)*(n-1)<<"\n";
            return;
        }
        /*vector<vector<LL>> q(ub+1);
        for(int i=bd; i<(int)primes.size(); ++i){
            q[primes[i]].push_back(i);
        }*/
        priority_queue<pair<LL,LL>> pq;
        for(int i=bd; i<(int)primes.size(); ++i){
            pq.push({-primes[i],i});
        }
        vector<int> vlb(ub+1);
        int pos=1;
        for(int i=0; i<n; ++i){
            while(pos<=a[i]){
                vlb[pos]=i;
                ++pos;
            }
        }
        for(int i=pos; i<ub+1; ++i){
            vlb[i]=n;
        }
        LazySegmentTree<Add_Sum> seg(n);
        int l=0,u=0;
        LL th=(x+y-1)/y;
        for(int i=2; i<=ub; ++i){
            //u=lower_bound(a.begin(),a.end(),i)-a.begin();
            u=vlb[i];
            seg.update(l,u,y);
            //int newl=upper_bound(a.begin(),a.end(),i-th)-a.begin();
            int newl = (i-th+1>=0?vlb[i-th+1]:0);
            //int newl = vlb[i-th+1];
            for(int j=l; j<newl; ++j){
                seg.update(j,j+1,x-seg.query(j,j+1));
            }
            l=newl;
            while(!pq.empty() and pq.top().first==-i){
                auto aa=pq.top();
                pq.pop();
                DBG(i,primes[aa.second])
                //auto tmp1 = lower_bound(a.begin(),a.end(),i)-a.begin();
                //auto tmp2 = lower_bound(a.begin(),a.end(),i-primes[q[i][j]]+1)-a.begin();
                int tmp1=vlb[i],tmp2=vlb[i-primes[aa.second]+1];
                ans[aa.second]+=seg.query(tmp2,tmp1);
                if(i+primes[aa.second]<=ub){
                    pq.push({-(i+primes[aa.second]),aa.second});
                    //q[i+primes[aa.second]].push_back(aa.second);
                }
            }
        }
        cout << *min_element(ans.begin(),ans.end())<<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

