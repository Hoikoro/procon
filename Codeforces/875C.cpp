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

struct Edge{
    int from,to;
    Edge(int from,int to)
        : from(from),to(to){};
    Edge(){Edge(0,0);}
};
typedef vector<vector<Edge>> Graph;

struct StronglyConnectedComponents{
    vector<int> scrank,vis,po;
    Graph graph,rgraph;
    StronglyConnectedComponents(int n):scrank(n),vis(n),graph(n),rgraph(n){}
    private:
    void dfs(int a,Graph &g){
        vis[a]=1;
        for(int i=0; i<g[a].size(); ++i){
            if(!vis[g[a][i].to]) dfs(g[a][i].to,g);
        }
        po.push_back(a);
    }
    void rdfs(int a, int k, Graph &rg){
        scrank[a]=k;
        vis[a]=1;
        for(int i=0; i<rg[a].size(); ++i){
            if(!vis[rg[a][i].to]) rdfs(rg[a][i].to,k,rg);
        }
    }
    public:
    void calc(){
        for(int i=0; i<graph.size(); ++i){
            if(!vis[i]) dfs(i,graph);
        }
        fill(vis.begin(),vis.end(),0);
        int c=0;
        for(int i=rgraph.size()-1; i>=0; --i){
            if(!vis[po[i]]) rdfs(po[i],c++,rgraph);
        }
    }
    void add_edge(int a, int b){
        graph[a].emplace_back(a,b);
        rgraph[b].emplace_back(b,a);
    }
    bool satisfiable(){
        for(int i=0; i<(int)graph.size()/2; ++i){
            if(scrank[2*i]==scrank[2*i+1])return false;
        }
        return true;
    }
};

struct Problem{
    int n,m;
    StronglyConnectedComponents scc;
    vector<vector<int>> w;
    Problem(LL n, LL m):n(n),m(m),scc(2*m),w(n){};
    void no(){cout << "No" << "\n"; exit(0);}
    void solve(){
        for(int i=0; i<n; ++i){
            int s; cin >> s;
            w[i].resize(s+1);
            for(int j=0; j<s; ++j){
                cin >> w[i][j];
                w[i][j]--;
            }
            w[i][s]=-1;
        }
        for(int i=0; i<n-1; ++i){//i vs i+1
            int j=0;
            while(j<min((int)w[i].size(),(int)w[i+1].size()) and w[i][j]==w[i+1][j])++j;
            if(j==min((int)w[i].size(),(int)w[i+1].size()))continue;
            //for(int j=0; j<min((int)w[i].size()-1,(int)w[i+1].size()-1); ++j){
            if(w[i+1][j]==-1)no();
            if(w[i][j]==-1)continue;
            DBG(w[i][j],w[i+1][j])
            if(w[i][j]>w[i+1][j]){//2w[i][j]+1 and 2w[i+1][j]
                scc.add_edge(2*w[i][j],2*w[i+1][j]+1);
                scc.add_edge(2*w[i+1][j]+1,2*w[i][j]);
                scc.add_edge(2*w[i+1][j],2*w[i][j]+1);
                scc.add_edge(2*w[i][j]+1,2*w[i+1][j]);
                scc.add_edge(2*w[i][j],2*w[i+1][j]);
                scc.add_edge(2*w[i+1][j]+1,2*w[i][j]+1);
            }
            DBG(i,w[i],w[i+1])
            if(w[i][j]<w[i+1][j]){
                scc.add_edge(2*w[i+1][j]+1,2*w[i][j]+1);
                scc.add_edge(2*w[i][j],2*w[i+1][j]);
            }
            //}
        }
        scc.calc();
        if(scc.satisfiable()){
            cout << "Yes" <<"\n";
            vector<int> ans;
            for(int i=0; i<m; ++i){
                if(scc.scrank[2*i]<scc.scrank[2*i+1]) ans.push_back(i);
            }
            cout << (int)ans.size() << "\n";
            for(int i=0; i<(int)ans.size(); ++i){
                cout << ans[i]+1 <<((i!=(int)ans.size()-1)?" ":"\n");
            }
        }else no();
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

