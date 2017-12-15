#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
#include <random>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

typedef pair<int,int> pii;
struct Edge{
    int from,to;
    double cost;
    Edge(int from,int to,double cost)
        : from(from),to(to),cost(cost) {};
};
typedef vector<vector<Edge>> Graph;

double dijkstra(const int start,const int goal, const vector<vector<Edge>> &graph , vector<int> &prev){
    typedef pair<double,int> pii;
    int N = graph.size();
    vector<char> visited(N,false);
    // <<cost , where>, prev>
    priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>> > que;
    que.push(make_pair(make_pair(0,start),-1));
    while(not que.empty()){
        double cost;
        int where,from;
        cost = que.top().first.first;
        where = que.top().first.second;
        from=que.top().second;
        que.pop();
        if(visited[where]) continue;
        prev[where]=from;
        if(where == goal) return cost;
        visited[where] = true;
        for(int j=0;j<(int)graph[where].size();j++){
            que.push(make_pair(make_pair(graph[where][j].cost+cost,graph[where][j].to),where));
        }
    }
    return -1;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    double sx,sy,gx,gy;
    int n;
    cin >> sx>>sy>>gx>>gy>>n;
    vector<double> x(n+1),y(n+1),r(n+1);
    FOR(i,1,n+1){
        cin >> x[i]>> y[i]>>r[i];
    }
    Graph G(n+2);
    G[0].push_back(Edge(0,n+1,sqrt((gx-sx)*(gx-sx)+(gy-sy)*(gy-sy))));
    FOR(i,1,n+1){
        double tos=sqrt((x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy));
        double tog=sqrt((x[i]-gx)*(x[i]-gx)+(y[i]-gy)*(y[i]-gy));
        G[0].push_back(Edge(0,i,max(tos-r[i],0.0)));
        G[i].push_back(Edge(i,n+1,max(tog-r[i],0.0)));
    }
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            double tmp=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            G[i].push_back(Edge(i,j,max(tmp-r[i]-r[j],0.0)));
            G[j].push_back(Edge(j,i,max(tmp-r[i]-r[j],0.0)));
        }
    }
    vector<int> p(n+2);
    cout << fixed << setprecision(12)<<dijkstra(0,n+1,G,p)<<endl;
    return 0;
}
