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

struct RangeSum{
    using T = long long;
    T operator()(const T &a, const T &b){return a+b;}
    static constexpr T id(){return T(0);};
};

struct RangeAdd{
    using T = long long;
    T operator()(const T &a, const T &b){return a+b;};
    static constexpr T id(){return T(0);};
};

struct Sum_Add{
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
    LL n,m;
    LazySegmentTree<Sum_Add> seg;
    vector<LL> a;
    Problem(LL n, LL m):n(n),m(m),seg(m+2),a(n){};
    void add(int l, int r){
        seg.update(l,r,1);
        seg.update(r,r+1,-(r-l));
    }
    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        LL sum=0;
        for(int i=1; i<n; ++i){
            sum+=(a[i]+m-a[i-1])%m;
            if(a[i]>a[i-1]){
                add(a[i-1]+2,a[i]+1);
                //seg.update(a[i-1]+2,a[i]+1,1);
                //seg.update(a[i]+1,a[i]+2,-(a[i]-a[i-1]-1));
            }else{
                add(a[i-1]+2,m+1);
                add(1,a[i]+1);
                seg.update(1,2,m+1-a[i-1]-2);
                seg.update(a[i]+1,a[i]+2,-(m+1-a[i-1]-2));
            }
            for(int j=1; j<=m; ++j){
            }
        }
        LL sub = 0;
        for(int i=1; i<=m; ++i){
            sub=max(sub,seg.query(1,i+1));
        }
        cout << sum-sub <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

