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
    int n,p;
    cin >> n >> p;
    vector<VI> improve(n,VI(4));
    double ans=0;
    REP(i,n){
        int a[4];
        cin >>  a[0] >> a[1]>> a[2];
        a[3]=1;
        FOR(j,1,4) improve[i][j]=-a[j]+a[0];
        ans+=a[0];
    }
    VI dp(3*n+1);
    REP(i,n){
        for(int j=3*n; j>=1; --j){
            FOR(k,1,4){
                if(j-k>=0)dp[j]=max(dp[j],dp[j-k]+improve[i][k]);
            }
        }
    }
    cout << fixed<<setprecision(10)<<(ans-dp[p])/(double)n<<endl;

    return 0;
}
