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
#define _M 100010
string a="()*^^",s;

int calc(){
    int sum[_M][2]={},dp[_M][4]={};//(,),~,*
    FOR(i,1,s.size()+1){
        REP(j,2){
            sum[i][j]=sum[i-1][j];
            if(s[i-1]==a[j])sum[i][j]++;
        }
        //dump(sum[i][0])dump(sum[i][1])
        dp[i][0]=i;
        for(int j=3;j>0;--j){
            if(s[i-1]==a[j+1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=dp[i-1][j];
            }
            //cout << i << j << dp[i][j]<<endl;
        }
    }
    int ret=0,tmp=0;
    FOR(i,1,s.size()+1){
        if(dp[i][3]!=dp[i-1][3]){
            //dump(i)
            //dump(sum[i][0])dump(sum[tmp][0])dump(sum[s.size()][1])dump(sum[i][1])
            int l=(sum[dp[i][3]][0]-sum[tmp][0]);
            int r=(sum[s.size()][1]-sum[i][1]);
            ret+=l*r;
            tmp=dp[i][3];
        }
    }
    return ret;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >>s;
    int hidari=calc();
    swap(a[0],a[1]);
    reverse(ALL(s));
    int migi=calc();
    cout << migi<<' ' << hidari <<endl;

    return 0;
}
