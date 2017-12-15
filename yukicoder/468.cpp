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
#define dump(a) cerr<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

struct Edge{
    int from,to;
    int cost;
    Edge(int from,int to,int cost)
        : from(from),to(to),cost(cost) {};
};
typedef vector<vector<Edge>> Graph;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    VI in(n);
    Graph d(n);
    REP(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        d[a].push_back(Edge(a,b,c));
        ++in[b];
    }
    VI vis(n),early(n),late(n,INF);
    queue<int> Q;
    stack<int> S;
    Q.push(0);
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        S.push(now);
        for(auto e : d[now]){
            early[e.to]=max(early[e.to],early[e.from]+e.cost);
            ++vis[e.to];
            if(vis[e.to]==in[e.to]) Q.push(e.to);
        }
    }
    late[n-1]=early[n-1];
    while(!S.empty()){
        int now=S.top();
        S.pop();
        for(auto e : d[now]){
            late[e.from]=min(late[e.from],late[e.to]-e.cost);
        }
    }
    int p=0;
    REP(i,n){
        if(early[i]!=late[i])++p;
    }
    cout << early[n-1]<<' '<<p<<'/'<<n<<endl;



    return 0;
}
