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
constexpr LL  MOD=998244353;

struct Problem{
    int n;
    vector<LL> x,y,c;
    vector<vector<LL>> dp;
    Problem(LL n):n(n),x(n),y(n),c(n+1),dp (n+1,vector<LL>(n+1)){};

    void solve(){
        dp[0][0]=1;
        for(LL i=0; i<=n; ++i){
            dp[0][i]=1;
            dp[i][0]=1;
        }
        for(LL i=1; i<=n; ++i){
            for(LL j=1; j<=n; ++j){
                dp[i][j]=(dp[i][j-1]+dp[i-1][j])%MOD;
            }
        }
        //nCk = dp[n-k][k]
        for(LL i=0; i<n; ++i){
            cin >> x[i] >> y[i];
        }
        vector<LL> sum(n+1);
        for(int i=3; i<=n; ++i){
            for(int j=3; j<=i; ++j){
                sum[i]=(sum[i]+dp[i-j][j])%MOD;
            }
        }
        LL ans =sum[n];
        for(int i=n; i>0; --i){
            sum[i]=sum[i]-sum[i-1];
        }
        DBG(ans)
        for(int i=0; i<n; ++i){
            vector<LL> used(n);
            for(int j=i+1; j<n; ++j){
                if(used[j])continue;
                LL tmp =0;
                for(int k=j+1; k<n; ++k){
                    bool f =false;
                    if(x[i]==x[j] and x[i] == x[k])f=true;
                    else if(y[i]==y[j] and y[i] == y[k])f=true;
                    else if((x[k]-x[i])*(y[k]-y[j])==(x[k]-x[j])*(y[k]-y[i])) f=true;
                    DBG(i,j,k,f)
                    if(f){
                        used[k]=1;
                        tmp++;
                    }
                }
                DBG(tmp)
                ans = (ans-sum[tmp+2]+MOD)%MOD;
                DBG(ans)
            }
        }
        cout << (ans+MOD)%MOD <<endl;
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

