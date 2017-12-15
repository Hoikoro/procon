#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

struct Problem{
    LL n;
    vector<LL> dp;
    Problem(LL n):n(n),dp(n+1,-1){};
    /*LL calc(int x){
        DBG(x)
        if(x<0)return 1;
        if(dp[x]>=0)return dp[x];
        LL ret=((n-1)*(n-1)+calc(x-1))%MOD;
        for(int i=2; i<=n; ++i){
            ret=(ret+calc(x-i-1))%MOD;
        }
        DBG(x,ret)
        return dp[x]=ret;
    }*/
    void solve(){
        dp[0]=1;
        dp[1]=n;
        LL cnt=n-1;
        LL sum=0;
        for(int i=2; i<=n; ++i){
            dp[i]=((n-1)*(n-1)+dp[i-1]+cnt+sum)%MOD;
            sum=(sum+dp[i-2])%MOD;
            --cnt;
        }
        cout << dp[n] <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

