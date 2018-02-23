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
void add_edge(Graph &G, int a, int b, LL cap){
    G[a].push_back(Edge(a,b,cap));
    G[b].push_back(Edge(b,a,0));
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    Graph G(n+2);
    Flow flow(n+2);
    LL ans =0;
    vector<LL> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

    for(int i = 1 ; i <=n ; i++){
        LL price; cin >> price;
        if(price>0){
            ans += price;
            add_edge(G,0,i,price);
            add_edge(G,i,n+1,0);
        }else{
            add_edge(G,0,i,0);
            add_edge(G,i,n+1,-price);
        }
        for(int j=0; j<25; ++j){
            if(i%primes[j]==0){
                add_edge(G,i,i/primes[j],LINF);
            }
        }
    }
    cout << ans - maximumFlow(G,flow,0,n+1) << endl;

    return 0;
}
