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
using Graph = vector<vector<int>>;
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
    int n,m,q;
    Graph g;
    UnionFind uf;
    vector<int> h,height;
    vector<vector<int>> d,cnt;
    vector<vector<double>> sum;
    vector<int> diam;
    Problem(LL n):n(n),g(n),uf(n),h(n),height(n),d(n),cnt(n),sum(n),diam(n){};
    int dfs(int prev, int cur){
        if(g[cur].size()==1 and g[cur][0]==prev) return 0;
        for(auto &v : g[cur]){
            if(v!=prev){
                h[cur]=max(h[cur],dfs(cur,v)+1);
            }
        }
        return h[cur];
    }
    void twdfs(int prev, int cur){
        DBG(prev,cur)
        vector<int> hs;
        for(auto &v : g[cur]){
            hs.push_back(h[v]);
        }
        hs.push_back(-1);
        sort(hs.begin(),hs.end(),greater<int>());
        height[cur]=hs[0]+1;
        for(auto &v : g[cur]){
            if(v!=prev){
                if(h[v]==hs[0]) h[cur]=hs[1]+1;
                else h[cur]=hs[0]+1;
                twdfs(cur,v);
            }
        }
    }
    void solve(){
        cin >> m >> q;
        for(int i=0; i<m; ++i){
            int u,v;
            cin >> u >> v;
            --u;--v;
            g[u].push_back(v);
            g[v].push_back(u);
            uf.unite(u,v);
        }
        for(int i=0; i<n; ++i){
            if(uf.is_par(i)){
                dfs(-1,i);
                twdfs(-1,i);
                d[i].resize(uf.size(i)+1);
            }
        }
        for(int i=0; i<n; ++i){
            int r= uf.root(i);
            DBG(i,r,height[i])
            d[r][height[i]]++;
            diam[r]=max(diam[r],height[i]);
        }
        for(int i=0; i<n; ++i){
            if(uf.is_par(i)){
                sum[i].resize(diam[i]+1);
                cnt[i].resize(diam[i]+1);
                cnt[i][0]=d[i][0];
                for(int j=1; j<sum[i].size(); ++j){
                    sum[i][j]=sum[i][j-1]+d[i][j]*j;
                    cnt[i][j]=cnt[i][j-1]+d[i][j];
                }
            }
        }
        for(int i=0; i<q; ++i){
            double ans=0.0;
            int u,v;
            cin >> u >> v;
            --u;--v;
            u=uf.root(u);
            v=uf.root(v);
            if(u==v){
                cout << -1 <<"\n";
                continue;
            }
            if(diam[u]>diam[v])swap(u,v);
            DBG(diam[u],diam[v])
            for(int j=(diam[u]+1)/2; j<=diam[u]; ++j){
                DBG(d[u][j],sum[v][diam[v]]*d[u][j],cnt[v][diam[v]],d[u][j])
                if(diam[v]-j-1>=0)ans+=(double)cnt[v][diam[v]-j-1]*diam[v]*d[u][j];
                DBG(ans)
                ans+=sum[v][diam[v]]*d[u][j]+(double)cnt[v][diam[v]]*d[u][j]*(j+1);
                DBG(ans)
                if(diam[v]-j-1>=0)ans-=sum[v][diam[v]-j-1]*d[u][j]+(double)cnt[v][diam[v]-j-1]*d[u][j]*(j+1);
                DBG(ans)
            }
            DBG(u,v,ans,cnt[u][diam[u]],cnt[v][diam[v]])
            ans=ans/cnt[u][diam[u]]/cnt[v][diam[v]];
            cout << ans <<"\n";
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    long long n=0;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

