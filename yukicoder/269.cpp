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

//O(s^2logn)?
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,s,k;
    cin >> n >> s >> k;
    vector<vector<LL>> dp(n+1,VLL(s+1));
    dp[0][0]=1;
    fill(ALL(dp[1]),1);
    FOR(i,2,n+1){
        if(k==0)dp[i][0]=1;
        FOR(j,1,s+1){
            for(int h=0; j-i*h-k*(i-1)>=0 ;++h){
                dp[i][j]=(dp[i][j]+dp[i-1][j-i*h-k*(i-1)])%MOD;
            }
        }
    }
    cout<< dp[n][s]<<endl;
    return 0;
}
