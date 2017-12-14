#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

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

struct BiconnectedComponents{
    vector<int> ord,low,biccrank,ordered_v;
    vector<Edge> bridges;
    vector<vector<int>> bicc;
    BiconnectedComponents(int n): ord(n,-1),low(n,INF),biccrank(n,-1){}
    int dfs(const Graph &g, int par, int cur, int cnt){ //一つ前、現在位置、頂点を何個見たか
        if(ord[cur]>=0)return ord[cur];
        ord[cur]=cnt++;
        ordered_v.push_back(cur);
        for(auto &x : g[cur]){
            if(x.to!=par) low[cur]=min(low[cur],dfs(g,cur,x.to,cnt));
        }
        return low[cur];
    }
    bool is_bridge(int a, int b){
        if(ord[a]>ord[b]) swap(a,b);
        return ord[a]<low[b];
    }
    void no_bridge_dfs(const Graph &g, int par, int cur, int rank){//一つ前、現在位置、BICCrank
        if(biccrank[cur]>=0)return;
        biccrank[cur]=rank;
        bicc.back().push_back(cur);
        for(auto &x : g[cur]){
            DBG(cur,x.to)
            if(x.to!=par && ord[x.to]>ord[cur]){
                if(is_bridge(cur,x.to)) {bridges.emplace_back(cur,x.to);continue;}
                no_bridge_dfs(g,cur,x.to,rank);
            }
        }
    }
    //二重連結成分をまとめた木をtにつくる
    void calc(const Graph &g, Graph &t){
        dfs(g,-1,0,0);
        for(int i=0,k=0; i<g.size(); ++i){
            if(biccrank[ordered_v[i]]<0){
                bicc.push_back({});
                DBG(k)
                no_bridge_dfs(g,-1,ordered_v[i],k++);
            }
        }
        t.resize(bicc.size());
        for(auto &x : bridges){
            t[biccrank[x.from]].emplace_back(biccrank[x.from],biccrank[x.to]);
            t[biccrank[x.to]].emplace_back(biccrank[x.to],biccrank[x.from]);
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    Graph g(n),t;
    BiconnectedComponents bicc(n);
    for(int i=0; i<m; ++i){
        int a,b;
        cin >> a >> b;
        g[a].push_back(Edge(a,b));
        g[b].push_back(Edge(b,a));
    }
    bicc.calc(g,t);
    for(int i=0; i<n; ++i){
        DBG(i,bicc.biccrank[i]);
    }

    for(int i=0; i<bicc.bicc.size(); ++i){
        for(int j=0; j<bicc.bicc[i].size(); ++j){
            cout << bicc.bicc[i][j]<<' ';
        }
        cout <<endl;
    }
    for(int i=0; i<t.size(); ++i){
        cout << i<<' ';
        for(int j=0; j<t[i].size(); ++j){
            cout << t[i][j].to<<' ';
        }
        cout <<endl;
    }

    return 0;
}

