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
    LL cost,capacity;
};
typedef pair<LL,int> PLI;
typedef vector<unordered_map<int,Edge>> Graph;
typedef vector<unordered_map<int, LL>> Flow; //(to,flow)

bool dijkstra(const int start, const Graph &graph , vector<PLI> &prev, vector<LL> &h,Flow &F){
    int visited =0,N=graph.size();
    fill(prev.begin(),prev.end(),make_pair(LINF,-1));
    priority_queue<pair<PLI,int>,vector<pair<PLI,int>>,greater<pair<PLI,int>> > Q;
    Q.push(make_pair(make_pair(0,start),0));
    LL cost; int place,from;
    while(!Q.empty()){
        cost=Q.top().first.first; place = Q.top().first.second; from=Q.top().second;
        Q.pop();
        if(prev[place].second!=-1) continue;
        prev[place]={cost,from};
        visited++;
        if(visited==N) return true;
        for(auto &me : graph[place]){
            auto &e= me.second;
            if(e.capacity>F[place][e.to] && prev[e.to].second==-1){
                Q.push(make_pair(make_pair(e.cost+cost-h[e.to]+h[place],e.to),place));
            }
        }
    }
    return false;
}


bool bellman_ford(const int start, const Graph &graph , vector<PLI> &prev){
    int s=graph.size(); bool update=false;
    prev[start]=make_pair(0ll,start);
    for(int i=0; i<s; ++i,update=false){
        for(int j= 0; j<s;++j){
            for(auto &me : graph[j]){
                auto &e=me.second;
                if(e.capacity==0)continue;
                if(prev[j].first!=LINF && prev[e.to].first > prev[j].first +e.cost){
                    prev[e.to].first=prev[j].first+e.cost;
                    prev[e.to].second=j;
                    update=true;
                    if(i==s-1)return false;
                }
            }
        }
        if(!update)break;
    }

    return true;
}

long long minimumCostFlow(const Graph &G, int s, int t,LL f,Flow &F){
    LL ret=0;
    int size=G.size();
    vector<LL> h(size);
    vector<PLI> prev(size,{LINF,-1});
    for(bellman_ford(s,G,prev);f>0;dijkstra(s,G,prev,h,F)){
        if(prev[t].first==LINF) return -1;
        for(int i=0; i<size ; ++i) h[i]=min(h[i]+prev[i].first,LINF);
        LL d=f;
        for(int v= t; v!=s; v=prev[v].second){
            d=min(d,G[prev[v].second].at(v).capacity-F[prev[v].second][v]);
        }

        f-=d; ret+=d*h[t];
        for(int v=t;v!=s;v=prev[v].second){
            F[prev[v].second][v]+=d;
            F[v][prev[v].second]-=d;
        }
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;//vertex,edge
    LL flow;
    cin >> n >> m >> flow;
    Graph G(n);
    Flow F(n);
    for(int i = 0 ; i < m ; i++){
        int a,b;
        LL cost,cap;
        cin >> a >> b >> cap >>cost;
        G[a][b]=(Edge){a,b,cost,cap};
        G[b][a]=(Edge){b,a,-cost,0};
    }
    cout <<minimumCostFlow(G,0,n-1,flow,F)<<endl;

    return 0;
}