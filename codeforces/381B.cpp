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
#define int long long
typedef pair<int,int> pii;
struct Edge{
    int from,to;
    LL cost;
    Edge(int from,int to, LL cost)
        : from(from),to(to),cost(cost) {};
};
typedef vector<vector<Edge>> Graph;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,mdep=0;
    cin >> n;
    vector<LL> a(n+1);
    vector<vector<pair<int,LL>>> par(20,vector<pair<int,LL>>(n+1));
    vector<int> ans(n+1),dep(n+1);

    REPN(i,1,n) cin >> a[i];
    REP(i,n-1){
        cin >> par[0][i+2].FI >> par[0][i+2].SE;
    }
    Graph T(n+1);
    queue<int> Q;
    Q.push(1);
    vector<vector<int>> d(n+1);
    d[0].PB(1);
    FOR(i,2,n+1){
        T[par[0][i].FI].PB(Edge(par[0][i].FI,i,par[0][i].SE));
    }
    while(!Q.empty()){
        int nx=Q.front();
        Q.pop();
        for(auto x: T[nx]){
            if(1){
                Q.push(x.to);
                dep[x.to]=dep[x.from]+1;
                mdep=max(mdep,dep[x.to]);
                d[dep[x.to]].PB(x.to);
            }
        }
    }

    REP(i,19){
        REPN(j,1,n){
            par[i+1][j].FI=par[i][par[i][j].FI].FI;
            par[i+1][j].SE=par[i][j].SE+par[i][par[i][j].FI].SE;
        }
    }
    FOR(i,2,n+1){
        int cur=i;
        LL wnow=0;
        for(int j=19;j>=0;--j){
            if(wnow+par[j][cur].SE<=a[i]){
                wnow+=par[j][cur].SE;
                cur=par[j][cur].FI;
            }
        }
        ans[par[0][i].FI]++;
        ans[par[0][cur].FI]--;
        //cout << i << endl;
        //REPN(i,1,n-1)cout << ans[i]<<' ';
        //cout<< ans[n] <<endl;
    }
    for(int i=mdep;i>=0;i--){
        for(auto x: d[i]){
            ans[par[0][x].FI]+=ans[x];
        }
    }

    REPN(i,1,n-1)cout << ans[i]<<' ';
    cout<< ans[n] <<endl;

    return 0;
}
