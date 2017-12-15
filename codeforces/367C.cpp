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

#define IMAX (LL)9223372036854775807
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >>n;
    LL c[100100]={};
    vector<string> f,r;
    REP(i,n){
        cin >> c[i];
    }

    REP(i,n){
        string a; cin >> a;
        f.push_back(a);
        reverse(a.begin(),a.end());
        r.push_back(a);
    }
    LL dp[100100][2];
    Fill(dp,IMAX);

    dp[0][0]=0;
    dp[0][1]=c[0];

    REPN(i,1,n-1){
        if(f[i-1]<=f[i] && dp[i-1][0] < IMAX){
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        }
        if(f[i-1]<=r[i]&& dp[i-1][0] < IMAX){
            dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
        }
        if(r[i-1]<=f[i]&& dp[i-1][1] < IMAX){
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
        }
        if(r[i-1]<=r[i]&& dp[i-1][1] < IMAX){
            dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
        }
    }

    /*REP(i,n){
        REP(j,2){
            OUT(dp[i][j])
        }
    }*/

    if(min(dp[n-1][0],dp[n-1][1])==IMAX){
        cout << -1 <<endl;
    }else{
        cout << min(dp[n-1][0],dp[n-1][1]) <<endl;
    }



    return 0;
}
