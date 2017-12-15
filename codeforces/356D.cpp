#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>
#include <numeric>
using namespace std;

typedef long long LL; typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int mx,dp[1000]={0,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    FOR(i,2,1000){
        int a=pow(i,0.33334);
        dp[i]=dp[i-a*a*a]+1;
        if(dp[i]>=dp[mx]) mx=i;
        cout << i <<' '<<a <<' '<< ' ' <<dp[i] << ' ' << mx<< endl;

    }

    return 0;
}
