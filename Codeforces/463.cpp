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
const double eps=1e-12;
typedef vector<vector<double >> Matrix;
void multiply(const Matrix &a, const Matrix &b, Matrix &ret){ //ret=a*b
    int k=a.size(),l=a[0].size(),m=b[0].size();
    if(l!=b.size()) DBG("!size")
    for(int h=0;h<k;++h){
        for(int i=0;i<m;++i){
            ret[h][i]=0.0;
            for(int j=0;j<l;j++){
                ret[h][i]+=a[h][j]*b[j][i];
            }
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout <<fixed<< setprecision(11);
    int n,m;
    cin >> n >> m;
    if(n==2){cout<< 0 <<endl; return 0;}
    Matrix c(2*(n-2),vector<double>(1));
    vector<double> dp(n),lc(n),dp2(n,1e18);
    FOR(i,0,n-2) {
        cin >>c[i+(n-2)][0];
        lc[i+1]=c[i+(n-2)][0];
    }
    Matrix a((n-2)*2,vector<double>((n-2)*2));//p[1]~p[m-2]c[1]~c[n-2]
    Matrix b((n-2)*2,vector<double>((n-2)*2));//p[1]~p[m-2]c[1]~c[n-2]
    REP(i,n-2){
        REP(j,n-2){
            if(i<j && j<i+m+1){
                a[i][j]+=1.0;
                a[i][j+(n-2)]+=1.0;
            }
            if(i+j>=(n-2)*2-m){
                a[i][j]+=1.0;
                a[i][j+(n-2)]+=1.0;
            }
            if(i==j){
                a[i+(n-2)][j+(n-2)]+=1.0;
            }
            a[i][j]/=m;
            a[i][j+(n-2)]/=m;
        }
    }

    REP(i,20){
        multiply(a,a,b);
        swap(a,b);
    }

    Matrix p(2*(n-2),vector<double>(1));
    multiply(a,c,p);
    for(int i=n-2-m;i>=0;--i){
        FOR(j,i+1,i+m+1){
            dp[i]+=dp[j]+lc[j];
            dp2[i]=min(dp2[i],p[j-1][0]+lc[j]);
        }
        dp[i]=min(dp[i]/m,dp2[i]);
    }

    cout << dp[0]<<endl;


    return 0;
}
