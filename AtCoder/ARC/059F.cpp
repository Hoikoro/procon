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
    int n,l;
    vector<LL> dp;
    Problem(int n):n(n),dp (n+1){};
    long long modpow(long long a, long long n,long long mod=MOD){
        long long i=1,ret=1,p=a;
        while(i<=n){
            if(i&n) ret=(ret*p)%mod;
            i=(i<<1);
            p=(p*p)%mod;
        }
        return ret;
    }
    void solve(){
        string s;
        cin >> s;
        l=s.length();
        dp[0]=1;
        for(int i=0; i<n; ++i){
            vector<LL> dp2(n+1);
            for(int j=0; j<=n; ++j){
                dp2[max(0,j-1)]+=dp[j];
                if(j<n)dp2[j+1]+=dp[j]*2;
            }
            for(int i=0; i<=n; ++i){
                dp2[i]%=MOD;
            }
            swap(dp,dp2);
        }
        cout << dp[l]*modpow(2,(MOD-2)*l)%MOD <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

