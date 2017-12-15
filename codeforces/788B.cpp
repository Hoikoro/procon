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

using Graph = vector<vector<int>> ;
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
    vector<LL> cnt;
    multiset<int> self;
    vector<pair<int,int>> edges;
    UnionFind uf;
    Problem(LL n, LL m):n(n),m(m),g(n),cnt(n),uf(n){};
    void fail (){cout << 0 <<"\n"; exit(0);}
    void solve(){
        LL ans =0;
        for(int i=0; i<m; ++i){
            int s,t;
            cin >> s >> t;
            --s; --t;
            if(s==t){
                self.insert(s);
            }else{
                g[s].push_back(t);
                g[t].push_back(s);
                edges.emplace_back(s,t);
                uf.unite(s,t);
            }
        }
        for(int i=0; i<n; ++i){
            cnt[i]=(LL)g[i].size();
        }
        int par =-1;
        for(int i=0; i<n; ++i){
            if(cnt[i]>0 or self.count(i)>0){
                if(par==-1){
                    par=uf.root(i);
                }else if(uf.root(i)!=par){
                    fail();
                }
            }
        }
        for(int i=0; i<(int)edges.size(); ++i){
            int s=edges[i].first;
            int t=edges[i].second;
            ans+=cnt[s]+cnt[t]-2;
        }
        ans/=2;
        ans+=(LL)self.size()*((LL)self.size()-1)/2;
        ans+=(LL)self.size()*(LL)edges.size();
        cout << ans <<"\n";
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

