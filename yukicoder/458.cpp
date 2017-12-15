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
void pre(int n,VI &p){
    p.push_back(2);
    FOR(i,3,n+1){
        bool f=true;
        for(int a : p){
            if(i%a==0) f=false;
        }
        if(f) p.push_back(i);
    }
    return ;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    VI p;
    pre(n,p);
    vector<VI> dp(n+1,VI(p.size()+1,-1));
    fill(ALL(dp[0]),0);
    FOR(i,2,n+1){
        FOR(j,1,p.size()+1){
            if(i-p[j-1]<0) dp[i][j]=dp[i][j-1];
            else if(dp[i-p[j-1]][j-1]<0)dp[i][j]=dp[i][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i-p[j-1]][j-1]+1);
        }
    }
    cout << dp[n][p.size()]<<endl;
    return 0;
}
