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

#define MOD 1000000007
#define int LL

long long pow_(long long a, long long n){
    if(n==0) return 1;
    long long re=pow_((a*a)%MOD,n/2)%MOD;
    if(n%2==1) re= (re*a)%MOD;
    return re%MOD;
}

LL nck(LL n, LL k){
    LL re=1;
    for(LL i = 1; i<=k; ++i){
        re=(re*(n-i+1))%MOD;
        re=(re*pow_(i,MOD-2))%MOD;
    }
    return re%MOD;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL h,w,a,b;
    cin >> h>>w>>a>>b;

    LL ans= nck(h+w-2,w-1);
    LL bef,aft;
    for(LL k=1 ; k <= b ; ++k){
        if(k==1){
            bef=1;
            aft=nck(a+w-2,w-1);
        }else{
            bef=(bef*(h+k-a-2))%MOD;
            bef=(bef*pow_(k-1,MOD-2))%MOD;
            aft=(aft*(a+w-k-a+1))%MOD;
            aft=(aft*pow_(a+w-k,MOD-2))%MOD;
        }
        ans=(ans-(bef*aft)%MOD+MOD)%MOD;

    }
    cout << ans << endl;
    return 0;
}
