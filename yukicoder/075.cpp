//Gauss-Seidel method
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
double solve(int K) {
    vector<double> dp(K+6);
    for (int t = 0; t < 100; t++) {
        for (int i = 0; i < K; i++) {
            double tmp = 6;
            for (int j = 1; j <= 6; j++) {
                if (i+j > K) tmp += dp[0];
                else tmp += dp[i+j];
            }
            dp[i] = tmp/6;
        }
        REP(i,K) printf("%.4lf%s",dp[i], (i==K-1)?"\n":" ");
    }
    return dp[0];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int K;
    cin >> K;
    printf("%.14lf\n", solve(K));
    return 0;
}
