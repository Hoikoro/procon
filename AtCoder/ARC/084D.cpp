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

struct Problem{
    typedef pair<int,int> pii;
    struct Edge{
        int from,to;
        LL cost;
        Edge(int from,int to,LL cost)
            : from(from),to(to),cost(cost) {};
    };
    typedef vector<vector<Edge>> Graph;

    LL dijkstra(const int start,const int goal, const vector<vector<Edge>> &graph , vector<int> &prev){
        // start, goal, graph, previous vertex on the shortest pass (prev[start]=-1)
        // <<cost , place>, prev>
        typedef tuple<LL,int,int> T;
        int N = graph.size();
        vector<LL> dist(N,LINF);
        vector<char> visited(N,false);
        priority_queue<T,vector<T>,greater<T> > Q;
        Q.push(make_tuple(0,start,-1));
        while(!Q.empty()){
            LL cost;
            int place,from;
            tie(cost,place,from)=Q.top();
            Q.pop();
            if(visited[place]) continue;
            prev[place]=from;
            if(place == goal) return cost;
            dist[place]=cost;
            visited[place] = true;
            for(int j=0;j<(int)graph[place].size();j++){
                if(dist[graph[place][j].to]<=graph[place][j].cost+cost)continue;
                Q.push(make_tuple(graph[place][j].cost+cost,graph[place][j].to,place));
            }
        }
        return -1;
    }
    int k;
    Graph g;
    Problem(LL n):k(n),g(k+1){};

    void solve(){
        if(k == 1){cout << 1 <<endl;return;}
        for(int i=0; i<k; ++i){
            for(int j=0; j<10; ++j){
                int to = (i*10+j)%k;
                if(i*j>0 and to==0)to=k;
                g[i].push_back(Edge(i,to,j));
            }
        }
        vector<int> prev(k+1);
        cout << dijkstra(0,k,g,prev) <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin >> n;
    while(n%2==0)n/=2;
    while(n%5==0)n/=5;
    Problem p(n);
    p.solve();
    return 0;
}

