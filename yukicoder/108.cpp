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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tmp,n,cnt[4]={};
    double dp[101][101][101]={};
    cin >> n;
    REP(i,n){
        cin >> tmp;
        if(tmp<3)cnt[3-tmp]++;
    }
    REP(i,n+1){
        REP(j,n+1-i){
            REP(k,n+1-i-j){
                //cout << i << ' ' << j << ' '<< k << ' '<< dp[i][j][k]<<endl;
                if(j!=0){
                    dp[i+1][j-1][k]+=(dp[i][j][k]+(double)n/(i+j+k))*(double)(i+1)/(i+j+k);
                }
                if(k!=0){
                    dp[i][j+1][k-1]+=(dp[i][j][k]+(double)n/(i+j+k))*(double)(j+1)/(i+j+k);
                }
                if(i+j+k<n){
                    dp[i][j][k+1]+=(dp[i][j][k]+(double)n/(i+j+k+1))*(double)(k+1)/(i+j+k+1);
                }
            }
        }
    }
    cout <<fixed<<setprecision(10);
    cout<<dp[cnt[3]][cnt[2]][cnt[1]]<<endl;

    return 0;
}
