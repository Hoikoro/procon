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

vector<int> sc;
int n,tmp,dp[220000],to[220000];

int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);

    fill(dp,dp+220000,500000);

    scanf("%d" , &n);
    REP(i,n){
        cin >>tmp;
        to[i+1]=tmp;
        sc.push_back(tmp);
    }
    sort(sc.begin(),sc.end());
    sc.erase(unique(sc.begin(),sc.end()),sc.end());
    dp[1]=0;
    dp[to[1]]=min(dp[to[1]],1);
    REPN(i,2,n-1){
        if(sc.front()<=i) sc.erase(sc.begin());
        dp[i]=min(dp[i],dp[i-1]+1);
        dp[i]=min(dp[i],dp[sc.front()]+abs(sc.front()-i));

        dp[to[i]]=min(dp[to[i]],dp[i]+1);
}
    REP(i,n-1){
        printf("%d ",dp[i+1]);
    }
    cout <<dp[n]<< endl;



    return 0;
}
