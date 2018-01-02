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
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
struct Edge{
    int from,to;
    LL cost;
    Edge(int from,int to,LL cost)
        : from(from),to(to),cost(cost) {};
};
typedef vector<vector<Edge>> Graph;
unordered_map<int,pair<LL,int>> dp[5050]; //<cities,<time,prev>>

void bfs(Graph &g, vector<int> & tp,int index){
    int n=g.size(), s=tp[index];
    if(index==tp.size()-1) return;
    for(auto e : g[s]){
        for(auto x : dp[s]){
            if(dp[e.to].find(x.first+1)==dp[e.to].end()){
                dp[e.to][x.first+1]=make_pair(x.second.first+e.cost,s);
            }else{
                if(dp[e.to][x.first+1].first>x.second.first+e.cost)
                dp[e.to][x.first+1]=make_pair(x.second.first+e.cost,s);
            }
        }
    }
    bfs(g, tp, index+1);
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    LL t;
    cin >> n >> m >> t;
    Graph G(n+1);
    vector<set<int>> REV(n+1);
    vector<int> tp,ans;
    for(int i=0;i<m;i++){
        int a,b;
        LL cost;
        cin >> a >> b >> cost;
        if(a==n or b==1) continue;
        G[a].push_back(Edge(a,b,cost));
        REV[b].insert(a);
    }
    queue<int> Q;
    REPN(i,1,n) if(REV[i].empty()) Q.push(i);
    while(!Q.empty()){
        int a=Q.front();
        tp.push_back(a);
        Q.pop();
        for(auto e : G[a]){
            REV[e.to].erase(a);
            if(REV[e.to].empty()){
                Q.push(e.to);
            }
        }
    }
    int tmp1,tmp2;
    dp[1][1]=make_pair(0ll,-1);
    bfs(G,tp,0);
    for(int i=n;i>0;--i){
        if(dp[n].find(i)!=dp[n].end() and dp[n][i].first<=t){
            cout << i << endl;
            tmp1=i;
            tmp2=dp[n][i].second;
            ans.push_back(n);
            break;
        }
    }
    while(true){
        ans.push_back(tmp2);
        tmp2=dp[tmp2][--tmp1].second;
        if(tmp2==-1)break;
    }
    for(auto j=ans.rbegin(); j!=ans.rend(); j++){
        cout <<  *j << ' ';
    }
    cout << endl;




    return 0;
}
