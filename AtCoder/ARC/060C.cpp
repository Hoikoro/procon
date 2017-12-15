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
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;
long long pow_(long long a, long long n){
    if(n==0) return 1;
    long long re=pow_(a*a,n/2);
    if(n%2==1) re= re*a;
    return re;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL dp[55][2525]={},u[55][2525]={};

    int n,a;
    cin >> n>>a;
    vector<int> x;
    REP(i,n){
        int t;
        cin >> t;
        x.push_back(t);
    }
    sort(x.begin(),x.end());
    int lb=lower_bound(x.begin(),x.end(),a)-x.begin();
    int ub=upper_bound(x.begin(),x.end(),a)-x.begin();
    LL b=ub-lb;
    b=pow_(2,b);
    dp[0][0]=1;u[0][0]=1;
    REPN(i,1,lb){
        REP(j,2501){
            dp[i][j]=dp[i-1][j];
            if(j>=a-x[i-1]){
                dp[i][j]+=dp[i-1][j-a+x[i-1]];
            }
        }
    }
    REPN(i,1,n-ub){
        REP(j,2501){
            u[i][j]=u[i-1][j];
            if(j>=x[i+ub-1]-a){
                u[i][j]+=u[i-1][j+a-x[i+ub-1]];
            }
        }
    }
    //OUT(u[2][1])
    LL ans=b-1;

    REPN(i,1,2500){
        ans+=(LL)dp[lb][i]*u[n-ub][i]*b;
    }
    cout << ans <<endl;

    return 0;
}
