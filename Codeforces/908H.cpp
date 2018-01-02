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
long long modpow(long long a, long long n,long long mod=MOD){
        long long i=1,ret=1,p=a;
        while(i<=n){
            if(i&n) ret=(ret*p)%mod;
            i=(i<<1);
            p=(p*p)%mod;
        }
        return ret;
    }
template<long long Mod=MOD>
struct Modint{
    public:
    //long long Mod = MOD;
    long long v;
    template<typename T> Modint(T x){
        x %= Mod;
        long long y = (long long)x;
        if(y<0) y+=Mod;
        v=y;
    }
    Modint():v(0){}
    Modint &operator+=(Modint a){
        v=(v+a.v);
        if(v>=Mod) v-=Mod;
        return *this;
    }
    Modint &operator-=(Modint a){
        v=(v-a.v);
        if(v<0)v+=Mod;
        return *this;
    }
    Modint &operator*=(Modint a){
        v=(v*a.v)%Mod;
        return *this;
    }
    Modint &operator/=(Modint a){
        v=(v*modpow(a.v,Mod-2))%Mod;
        return *this;
    }
    Modint operator+(Modint a){
        long long t= (v)+(a.v);
        return Modint(t);
    }
    Modint operator-(Modint a){
        long long t= (v)-(a.v);
        return Modint(t);
    }
    Modint operator*(Modint a){
        long long t= (v)*(a.v);
        return Modint(t);
    }
    Modint operator/(Modint a){
        long long t=(v)*modpow(a.v,Mod-2);
        return Modint(t);
    }
};
ostream& operator<< (ostream& os, const Modint<> m) {
    return os << m.v;
}
struct UnionFind{
    vector<int> par; //par: -1*elements(root) number of par(not root)
    UnionFind(int n){par = vector<int>(n,-1);}
    int root(int x){return par[x]<0?x:(par[x]=root(par[x]));}
    void unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            par[y] += par[x];
            par[x] = y;
        }
    }
    bool is_root(int x){return root(x)==x;}
    bool same(int x,int y){return root(x) == root(y);}
    int size(int x){return -par[root(x)];}
};
struct Problem{
    int n;
    vector<vector<char>> c;
    vector<vector<int>> g;
    UnionFind uf;
    Problem(LL n):n(n),c (n,vector<char>(n)),uf(n){};
    void solve(){cout << calc() <<"\n";}
    int calc(){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cin >> c[i][j];
                if(c[i][j]=='A'){
                    uf.unite(i,j);
                }
            }
        }
        vector<int> par_id(n,-1);
        int cnt2=0;
        for(int i=0; i<n; ++i){
            if(uf.is_root(i)){
                if(uf.size(i)>1)par_id[i]=cnt2++;
            }
        }
        g= vector<vector<int>> (cnt2,vector<int>(cnt2));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(c[i][j]=='X'){
                    if(uf.same(i,j))return -1;
                    if(uf.size(i)>1 and uf.size(j)>1)g[par_id[uf.root(i)]][par_id[uf.root(j)]]=1;
                }
            }
        }
        return n-1+chromatic_number(g);
    }
    int chromatic_number(vector<vector<int>> &graph){
        //smallest number of colors needed to color the input graph; coloring
        int sz = (int)graph.size();
        int ub = sz;
        int lb = 0;
        vector<int> adj(sz);
        for(int i=0; i<sz; ++i){
            for(int j=0; j<sz; ++j){
                adj[i]+=((i==j or graph[i][j]>0)<<j);
            }
        }
        vector<Modint<>> dp(1<<sz);
        dp[0]=1;
        for(int i=1; i<(1<<sz); ++i){
            int v=__builtin_ctz(i);
            dp[i]=(dp[i-(1<<v)]+dp[i&(~adj[v])]);
        }
        while(ub-lb>1){
            int mid = (ub+lb)/2;
            if(is_colorable(dp,mid))ub=mid;
            else lb=mid;
        }
        return ub;
    }
    bool is_colorable(vector<Modint<>> &dp, int colors){
        Modint<> res = 0;
        for(int i=0; i<(int)dp.size(); ++i){
            if(__builtin_popcount(i)%2)res+=modpow(dp[i].v,colors);
            else res-=modpow(dp[i].v,colors);
        }
        return res.v!=0;
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

