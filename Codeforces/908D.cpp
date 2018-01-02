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
    LL k,pa,pb,pp;
    void solve(){
        cin >> k >> pa >> pb;
        pp=pa+pb;
        vector<vector<LL>> dp (k+1,vector<LL>(k));
        dp[1][0]=1;
        LL ans=0;
        for(LL i=1; i<=k; ++i){
            for(LL j=0; j<k-i; ++j){
                dp[i][j+i]+=(dp[i][j]*pb%MOD)*modpow(pp,min(i-1,k-1-i-j));
                dp[i][j+i]%=MOD;
                dp[i+1][j]+=dp[i][j]*pa;
                dp[i+1][j]%=MOD;
            }
            for(LL j=k-i; j<k; ++j){
                ans+=dp[i][j]*(((j+i)*pb+pa)%MOD)%MOD;
                ans%=MOD;
            }
        }
        LL den=modpow(modpow(pp,k-1)*pb%MOD,MOD-2);
        cout << ans*den%MOD << "\n";
    }
    long long modpow(long long a, long long n,long long mod=MOD){
        long long i=1,ret=1,p=a;
        while(i<=n){
            if(i&n) ret=(ret*p)%mod;
            i=(i<<1);
            p=(p*p)%mod;
        }
        return ret;
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    Problem p;
    p.solve();
    return 0;
}

