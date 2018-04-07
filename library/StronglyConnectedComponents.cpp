#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;
using LL = long long;

struct Edge{
    int from, to;
    Edge(int from, int to)
        : from(from), to(to){};
    Edge() { Edge(0, 0); }
};
using Graph = vector<vector<Edge>>;

struct StronglyConnectedComponents{
    int cnt;
    vector<int> scrank, visited, postorder;
    Graph graph, rgraph;
    vector<vector<int>> scc_dag,inv; //scc_dag : contracted graph
    StronglyConnectedComponents(int n) : scrank(n, -1), visited(n), graph(n), rgraph(n) {}
    StronglyConnectedComponents(Graph &g, Graph &rg) : scrank((int)g.size(), -1), visited((int)g.size()){
        graph = g;
        rgraph = rg;
    }

  private:
    void dfs(int a, Graph &g){
        visited[a] = 1;
        for (int i = 0; i < g[a].size(); ++i){
            if (!visited[g[a][i].to]) dfs(g[a][i].to, g);
        }
        postorder.push_back(a);
    }
    void rdfs(int s, int r, Graph &rg){
        scrank[s] = r;
        visited[s] = 1;
        for (int i = 0; i < rg[s].size(); ++i){
            if (!visited[rg[s][i].to])rdfs(rg[s][i].to, r, rg);
        }
    }

  public:
    void calc(){
        for (int i = 0; i < graph.size(); ++i){
            if (!visited[i]) dfs(i, graph);
        }
        fill(visited.begin(), visited.end(), 0);
        int rank = 0;
        for (int i = rgraph.size() - 1; i >= 0; --i){
            if (!visited[postorder[i]]) rdfs(postorder[i], rank++, rgraph);
        }
        cnt = rank;
        scc_dag.resize(rank);
        inv.resize(rank);
        for(int i=0; i<(int)graph.size(); ++i){
            inv[scrank[i]].push_back(i);
        }
    }
    void calc_with_DAG(){
        calc();
        for(int i=0; i<(int)graph.size(); ++i){
            for(auto v : graph[i]){
                if(scrank[v.to]>scrank[i])scc_dag[scrank[i]].push_back(scrank[v.to]);
            }
        }
        for(auto &vec : scc_dag){
            sort(vec.begin(),vec.end());
            vec.erase(unique(vec.begin(),vec.end()),vec.end());
        }
    }
    void add_edge(int a, int b){
        graph[a].emplace_back(a, b);
        rgraph[b].emplace_back(b, a);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    Graph g(n), rev(n);
    StronglyConnectedComponents scc(n);
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        scc.add_edge(a,b);
    }
    scc.calc();
    for(int i=0; i<n; ++i){
        cout << scc.scrank[i] << endl;
    }

    return 0;
}
