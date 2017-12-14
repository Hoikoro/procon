#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

//Dinic法による最大流

struct Edge{
    int from,to;
    LL capacity;
    Edge(int from,int to, LL capacity)
        : from(from),to(to),capacity(capacity) {};
};
typedef pair<int,int> pii;
typedef vector<vector<Edge>> Graph;
typedef vector<unordered_map<int, LL>> Flow; //(to,flow)
//typedef vector<vector<LL>> Flow;

LL add_flow(const Graph &g, Flow &flow, const vector<int> &level, vector<int> &iter, int u, int t, LL cur){
    if(u==t || cur==0) return cur;
    for(int &i= iter[u];i<g[u].size();++i){
        auto e=g[u][i];
        if(level[e.to] > level[u]){
            LL f= add_flow(g, flow, level, iter, e.to, t, min(cur,e.capacity-flow[e.from][e.to]));
            if(f > 0){
                flow[e.from][e.to] += f;
                flow[e.to][e.from] -= f;
                return f;
            }
        }
    }
    return 0;
}

LL maximumFlow(const Graph &g, Flow &flow, int s, int t){
    const LL INF=1<<30;
    int n=g.size();
    LL total=0;
    for(bool cont = true ; cont;){
        cont =false;
        vector<int> level(n,-1);
        level[s]=0;
        queue<int> Q;
        Q.push(s);
        for(int d = n; !Q.empty() && level[Q.front()] < d;){
            int u = Q.front();
            Q.pop();
            if(u == t) d = level[u];
            for(auto e : g[u]){
                if(e.capacity>flow[e.from][e.to] && level[e.to]==-1){
                    Q.push(e.to);
                    level[e.to]=level[u]+1;
                }
            }
        }
        vector<int> iter(n);
        while(true){
            LL f=add_flow(g,flow,level,iter,s,t,INF);
            if(f==0)break;
            total += f;
            cont = true;
        }
    }
    return total;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; //vertex,edge
    cin >> n >> m;
    Graph G(n);
    Flow flow(n);
    for(int i = 0 ; i < m ; i++){
        int a,b;
        LL cost,cap;
        cin >> a >> b >>cap;
        G[a].push_back(Edge(a,b,cap));
        G[b].push_back(Edge(b,a,0));
    }
    cout << maximumFlow(G,flow,0,n-1) << endl;

    return 0;
}