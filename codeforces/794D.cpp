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
using Graph= vector<vector<int>> ;
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
    bool is_par(int x){return root(x)==x;}
    bool same(int x,int y){return root(x) == root(y);}
    int size(int x){return -par[root(x)];}
};
struct Problem{
    int n,m;
    Graph g;
    vector<int> ans;
    UnionFind uf;
    vector<vector<int>> div;
    int fa;
    Problem(LL n, LL m):n(n),m(m),g(n),ans(n),uf(n),div(n),fa(0){};
    void fail(){cout <<"NO"<<"\n"; exit(0);}
    bool comp(int s, int t,vector<int> &a, vector<int> &b){
        if(a.size()!=b.size())return false;
        int i=0,j=0,sz=a.size();
        for(;i<sz and j<sz;++i,++j){
            if(a[i]==t)++i;
            if(b[j]==s)++j;
            if(i==sz or j==sz)break;
            if(a[i]!=b[j])return false;
        }
        return true;
    }
    void dfs1(int par,int cur,int dif){
        if((int)g[cur].size()==1 and g[cur][0]==par) return;
        int x=-1;
        for(auto y:g[cur]){
            if(ans[y]==0){
                x=uf.root(y);
                break;
            }
        }
        DBG(x)
        if(x==-1)return;
        for(auto y:div[x]){
            ans[y]=ans[cur]+dif;
        }
        DBG(ans)
        dfs1(cur,x,dif);
    }


    void solve(){
        for(int i=0; i<m; ++i){
            int a,b; cin >> a >>b;
            --a;--b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=0; i<n; ++i){
            sort(g[i].begin(),g[i].end());
        }
        for(int i=0; i<n; ++i){
            for(auto & x : g[i]){
                if(comp(i,x,g[i],g[x])){
                    uf.unite(i,x);
                }
            }
        }
        for(int i=0; i<n; ++i){
            div[uf.root(i)].push_back(i);
        }
        for(auto x: div[uf.root(0)]){
            ans[x]=5e7;
        }
        dfs1(-1,0,1);
        DBG(n)
        dfs1(-1,0,-1);
        for(int i=0; i<n; ++i){
            if(ans[i]==0)fail();
        }
        cout <<"YES"<<"\n";
        for(int i=0; i<n; ++i){
            cout << ans[i]<<' ';
        }
        cout <<"\n";
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

