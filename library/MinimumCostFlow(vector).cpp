#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

struct Edge{
    int from,to;
    LL cost,capacity;
    int rev_id;
};
typedef vector<vector<Edge>> Graph;
typedef vector<vector<LL>> Flow;
struct Prev{LL cost; int from, id;};

bool dijkstra(const int start, const Graph &graph , vector<Prev> &prev, vector<LL> &h,Flow &F){
    int visited =0,N=graph.size();
    fill(prev.begin(),prev.end(),(Prev){LINF,-1,-1});
    typedef tuple<LL,int,int,int> TP;
    priority_queue<TP,vector<TP>,greater<TP> > pque;
    pque.emplace(0,start,0,-1);
    LL cost; int place,from,id;
    while(!pque.empty()){
        tie(cost,place,from,id)=pque.top();
        //cout << cost<< ' '<< place << ' ' << from<<endl;
        pque.pop();
        if(prev[place].from!=-1) continue;
        prev[place]={cost,from,id};
        visited++;
        if(visited==N) return true;
        for(int i=0; i<(int)graph[place].size(); ++i){
        auto e = &graph[place][i];
            if(e->capacity>F[place][e->to] && prev[e->to].from==-1){
                pque.emplace(e->cost+cost-h[e->to]+h[place],e->to,place,i);
            }
        }
    }
    return false;
}


bool bellman_ford(const int start, const Graph &graph , vector<Prev> &prev){
    int s=graph.size();
    bool update=false;
    prev[start]=(Prev){0ll,start,-1};
    for(int i=0; i<s; ++i,update=false){
        for(int j= 0; j<s; ++j){
            for(auto &e : graph[j]){
                if(e.capacity==0)continue;
                if(prev[j].cost!=LINF && prev[e.to].cost > prev[j].cost +e.cost){
                    prev[e.to].cost=prev[j].cost+e.cost;
                    prev[e.to].from=j;
                    prev[e.to].id=e.rev_id;
                    update=true;
                    if(i==s-1)return false;
                }
            }
        }
        if(!update)break;
    }
    return true;
}

long long minimumCostFlow(const Graph &graph, int s, int t,LL f,Flow &F){
    LL ret=0;
    int size=graph.size();
    vector<LL> h(size);
    vector<Prev> prev(size,{LINF,-1,-1}); //mincost, from,id
    for(bellman_ford(s,graph,prev);f>0;dijkstra(s,graph,prev,h,F)){
        if(prev[t].cost==LINF) return -1;
        for(int i=0; i<size ; ++i) h[i]=min(h[i]+prev[i].cost,LINF);
        LL d=f;
        for(int v= t; v!=s; v=prev[v].from){
            //DBG(v)
            //DBG(prev[v].from)
            d=min(d,graph[prev[v].from][prev[v].id].capacity-F[prev[v].from][v]);
            //DBG(d)
        }
        f-=d; ret+=d*h[t];
        //DBG(ret)
        for(int v=t;v!=s;v=prev[v].from){
            F[prev[v].from][v]+=d;
            F[v][prev[v].from]-=d;
        }
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;  LL flow;
    cin >> n >> m>>flow;
    Graph g(n);
    Flow F(n,vector<LL>(n));
    for(int i = 0 ; i < m ; i++){
        int a,b;
        LL cost,cap;
        cin >> a >> b >> cap >>cost;
        g[a].push_back({a,b,cost,cap,(int)g[b].size()});
        g[b].push_back({b,a,-cost,0,(int)g[a].size()-1});
    }
    cout <<minimumCostFlow(g,0,n-1,flow,F)<<endl;

    return 0;
}