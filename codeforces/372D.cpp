#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

struct Edge{
    int from,to;
    LL cost;
    Edge(int from,int to,LL cost)
        : from(from),to(to),cost(cost) {};
};
int n,m,s,g;
LL l;
int bef[1010];

LL dijkstra(const int start,const int goal,
             const vector<vector<Edge> > &graph){
    typedef pair<LL,int> pii;
    int N = graph.size();
    vector<char> visited(N,false);
    // <<cost , where>, prev>
    priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>> > que;
    que.push(make_pair(make_pair(0,start),-1));
    while(not que.empty()){
        LL cost;
        int where,b;
        cost = que.top().first.first;
        where = que.top().first.second;
        b=que.top().second;
        que.pop();
        if(visited[where]) continue;
        bef[where]=b;
        if(where == goal) return cost;
        visited[where] = true;
        for(int j=0;j<(int)graph[where].size();j++){
            que.push(make_pair(make_pair(max(graph[where][j].cost,1ll)+cost,graph[where][j].to),where));
        }
    }
    return -1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m>> l >> s >> g;
    vector<vector<Edge> > V(n),Vpos(n);
    int q[m][3];
    REP(i,m){
        int a,b;
        LL cost;
        cin >> a >> b >> cost;
        q[i][0]=a;
        q[i][1]=b;
        q[i][2]=cost;
        V[a].push_back(Edge(a,b,cost));
        V[b].push_back(Edge(b,a,cost));
        if(cost!=0){
            Vpos[a].push_back(Edge(a,b,cost));
            Vpos[b].push_back(Edge(b,a,cost));
        }
    }
    LL cpos=dijkstra(s,g,Vpos);
    LL c=dijkstra(s,g,V);
    //OUT(c)
    //OUT(cpos)
    REP(i,n){
        //OUT(bef[i])
    }
    if(c==-1 or c > l or (0<cpos and cpos<l)){
        cout << "NO" << endl;
        return 0;
    }
    int u=g;
    bool al=false;
    while(bef[u]!=-1){
        REP(i,m){
            if(((q[i][0]==u&&q[i][1]==bef[u])||(q[i][1]==u&&q[i][0]==bef[u]))&&q[i][2]==0){
                if(!al){
                q[i][2]=l-c+1;
                }else{
                    q[i][2]=1;
                }
                al=true;
            }
        }
        u=bef[u];
    }
        cout << "YES" << endl;

    REP(i,m){
        if(q[i][2]==0){
        cout << q[i][0]<< ' ' << q[i][1] << ' ' << l <<endl;
        }else{
            cout << q[i][0]<< ' ' << q[i][1] << ' ' << q[i][2]<<endl;
        }
    }




    return 0;
}
