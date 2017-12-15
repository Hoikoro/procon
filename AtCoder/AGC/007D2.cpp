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
#define debug(a) cerr<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,e,t;
    cin >> n >> e >> t;
    VLL dp(n+1,LINF),x(n+1),dp2(n+1,LINF);
    REP(i,n) cin >> x[i+1];
    dp[0]=0;
    dp[1]=t;
    int l=(dp[0]-2*x[1]<dp[1]-2*x[2]?0:1);
    LL r=0;
    FOR(i,2,n+1){
        if(t<=2*(x[i]-x[l+1]))dp[i]=dp[l]+(x[i]-x[l+1])*2;
        /*for(int j= l; j<i ; ++j){
            if(dp[i]>dp[j]+max((LL)t,(x[i]-x[j+1])*2)){
                dp[i]=min(dp[i],dp[j]+max((LL)t,(x[i]-x[j+1])*2));
                l=j;
            }
            if(t>(x[i]-x[j+1])*2){
                break;
            }
        }*/
        //debug(l)
        //debug(dp[i])
        for(int j=r ; j<i ; ++j){
            r=j;
            if(t>(x[i]-x[j+1])*2){
                dp[i]=min(dp[i],dp[r]+t);
                break;
            }
        }

        //debug(r)
        if(dp[l]+(x[i+1]-x[l+1])*2>dp[i]) l=i;
        //debug(dp[i])
    }
    cout << dp[n]+e<<endl;

    return 0;
}
