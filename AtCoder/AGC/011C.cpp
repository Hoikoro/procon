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
struct UnionFind{
    vector<int> par; //par: -1*elements(root) number of par(not root)
    UnionFind(int n){
        par = vector<int>(n,-1);
    }
    int root(int x){
        return par[x]<0?x:(par[x]=root(par[x]));
    }
    void unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            par[y] += par[x];
            par[x] = y;
        }
        return;
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    int size(int x){
        return -par[root(x)];
    }
};

struct Problem{
    LL n,m;
    vector<vector<int>> g;
    vector<int> vis;
    UnionFind uf;
    Problem(LL n, LL m):n(n),m(m),g(n),vis(n),uf(n){};
    bool oddloop(int s){
        queue<int> Q;
        Q.push(s);
        vis[s]=1;
        while(!Q.empty()){
            int cur=Q.front();Q.pop();
            for(int v : g[cur]){
                if(vis[v]==0){
                    vis[v]=3-vis[cur];
                    Q.push(v);
                }else{
                    if(vis[cur]==vis[v])return true;
                }
            }
        }
        return false;
    }

    void solve(){
        for(int i=0; i<m; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            g[a].push_back(b);
            g[b].push_back(a);
            uf.unite(a,b);
        }
        vector<int> vis(n);
        LL cnt=0, conn=0, ev=0;
        for(int i=0; i<n; ++i){
            if(uf.par[i]<-1){
                if(!oddloop(i))ev++;
                conn+=uf.size(i);
                cnt++;
            }
        }
        cout << n*n-conn*conn+cnt*cnt+ev*ev <<"\n";

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

