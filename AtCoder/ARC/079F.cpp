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
};


struct Problem{
    int n;
    vector<int> c,p,a,inc;
    vector<vector<int>> child,mex;
    vector<pair<int,int>> cond;
    Problem(LL n):n(n),p(n),a(n),inc(n),child(n),mex(n){};
    void cc(){
        vector<int> vis(n),vis2(n);
        int cur=0;
        for(;vis[cur]==0;cur=p[cur]){
            vis[cur]=1;
        }
        for(;vis2[cur]==0;cur=p[cur]){
            vis2[cur]=1;
            c.push_back(cur);
            inc[cur]=1;
        }
    }
    vector<int> dfs(int cur){
        DBG(cur)
        vector<int> tmp;
        for(auto x: child[cur]){
            if(inc[x]==0){
                dfs(x);
                tmp.push_back(a[x]);
            }
        }
        sort(tmp.begin(),tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        while(a[cur]<(int)tmp.size() and tmp[a[cur]]==a[cur] )a[cur]++;
        return tmp;
    }
    void solve(){
        for(int i=0; i<n; ++i){
            cin >> p[i];
            p[i]--;
            child[p[i]].push_back(i);
        }
        cc();
        for(int i=0; i<(int)c.size(); ++i){
            int x=c[i];
            mex[x]=dfs(x);
            int j=a[x];
            while(j<(int)mex[x].size() and mex[x][j]==j+1)j++;
            cond.push_back({a[x],j+1});
        }
        DBG(cond)
        DBG(c)
        StronglyConnectedComponents scc(2*(int)c.size());
        int si=(int)c.size();
        for(int i=0; i<(int)c.size(); ++i){
            int j=(i+1)%si;
            if(a[c[i]]==a[c[j]]){
                scc.add_edge(i*2,j*2+1),scc.add_edge(j*2,i*2+1);
            }
            if(a[c[i]]==cond[j].second){
                scc.add_edge(i*2,j*2),scc.add_edge(j*2+1,i*2+1);
            }
            if(cond[i].second==a[c[j]]){
                scc.add_edge(i*2+1,j*2+1),scc.add_edge(j*2,i*2);
            }
            if(cond[i].second==cond[j].second){
                scc.add_edge(i*2+1,j*2),scc.add_edge(j*2+1,i*2);
            }
            if(a[c[i]]==cond[j].first)scc.add_edge(i*2,j*2+1);
            else scc.add_edge(i*2,j*2);
            if(cond[i].second == cond[j].first)scc.add_edge(i*2+1,j*2+1);
            else scc.add_edge(i*2+1,j*2);
        }
        scc.calc();
        DBG(scc.scrank)
        for(int i =0; i<si; ++i) {
            if(scc.scrank[2*i]==scc.scrank[2*i+1]){
            cout << "IMPOSSIBLE"<<endl;
            return ;
            }
        }
        cout << "POSSIBLE"<<endl;

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

