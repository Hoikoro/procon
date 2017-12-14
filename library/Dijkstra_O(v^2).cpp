#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

// start, goal, graph
typedef pair<int,int> pii;
struct Edge{
    int from,to;
    LL cost;
    Edge(int from,int to,LL cost)
        : from(from),to(to),cost(cost) {};
};
typedef vector<vector<Edge>> Graph;

long long  dijkstra(const int s,const int t, const Graph &G){
    int N = G.size();
    vector<long long> dist(N,LINF);
    int now=s; dist[s]=0;
    while(now!=t){
        for(auto e: G[now]){
            dist[e.to]=min(dist[e.to],dist[now]+e.cost);
        }
        LL m=LINF;
        for(int i=0;i<N;++i){
            if(dist[now]<=dist[i] && dist[i]<m && i!=now){
                m=dist[i];
                now=i;
            }
        }
        if(m==LINF) return LINF;
    }
    return dist[t];
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,s,t; //vertex,edge
    cin >> n >> m;
    Graph G(n);
    //vector<int> prev(n);

    for(int i=0;i<m;i++){
        int a,b,cost;
        cin >> a >> b >> cost;
        G[a].push_back(Edge(a,b,cost));
        //G[b].push_back(Edge(b,a,cost));
    }

    cout<<dijkstra(s,t,G)<<endl;

    return 0;
}
