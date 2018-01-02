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
    V::T operator()(const V::T &a, const A::T &b, const LL &h){return a+(b<<h);};
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
    int n,m,q,vis;
    vector<vector<int>> g;
    vector<LL> line,visit;
    vector<LL> ub,l,r;
    LazySegmentTree<Sum_Add> seg;
    Problem(LL n, LL m):n(n),m(m),vis(0),g(n),visit(n),ub(n,n-1),l(n),r(n),seg(n){};

    void dfs(int c, int p=-1){
        DBG(c,p,visit)
        if(visit[c] and visit[c]<visit[p]){
            DBG(visit[c],visit[p])
            line.push_back(c);
            LL mini=INF,maxi=0;
            DBG(line)
            for(int i=(int)line.size()-1;i==(int)line.size()-1 or line[i]!=c; --i){
                DBG(i,line[i])
                mini=min(mini,line[i]);
                maxi=max(maxi,line[i]);

            }
            ub[mini]=min(ub[mini],maxi-1);
            //ub[mini+1]=min(ub[mini+1],maxi);
                DBG(ub)
            line.pop_back();
        }else if(!visit[c]){
            line.push_back(c);
            visit[c]=++vis;
            for(auto && v:g[c])if(v!=p){
                dfs(v,c);
            }
            line.pop_back();
        }
    }
    void solve(){
        for(int i=0; i<m; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=0; i<n; ++i){
            if(!visit[i])dfs(i);
        }
        DBG(n)
        cin >> q;
        LL sum=0;
        for(int i=n-1; i>=0; --i){
            if(i<n-1)ub[i]=min(ub[i],ub[i+1]);
            sum+=ub[i]-i+1;
            r[i]=sum;
            seg.update(i,ub[i]+1,1);
        }
        for(int i=0; i<n; ++i){
            l[i]=sum-r[i];
        }
        DBG(ub)
        for(int i=0; i<q; ++i){
            LL x,y; cin >> x >> y;
            --x;--y;
            if(y<=ub[x]){
                DBG(x,y)
                cout << (y-x+2)*(y-x+1)/2<<"\n";;
            }else{
                cout << sum-l[x]-seg.query(y+1,n)<<"\n";
            }
        }
    }
};

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

