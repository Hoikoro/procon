#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dbgsplit(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dbgsplit(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}
using LL = long long;
constexpr long long LINF=334ll<<53; constexpr int INF=15<<26; constexpr long long MOD=1E9+7;

long long modpow(long long a, long long n,long long mod=MOD){
    long long i=1,ret=1,p=a;
    while(i<=n){
        if(i&n) ret=(ret*p)%mod;
        i=(i<<1);
        p=(p*p)%mod;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    if(k==1){cout << 1 <<"\n"; return 0;}

    vector<vector<LL>> dp (n+1,vector<LL>(n+1));
    vector<LL> fac(n*k+1),inv(n*k+1);
    fac[0]=1;
    for(int i=1; i<=n*k; ++i){
         fac[i]=fac[i-1]*i%MOD;
     }
     inv[n*k]=modpow(fac[n*k],MOD-2);
     for(int i=n*k-1; i>=0; --i){
         inv[i]=inv[i+1]*(i+1)%MOD;
     }
     dp[0][0]=1;
     for(int i=1; i<=n; ++i){
        dp[i][0]=1;
         for(int j=1; j<=i; ++j){
             dp[i][j]=(dp[i-1][j]+((dp[i][j-1]*fac[n*k-i-(j-1)*(k-1)-1]%MOD)*inv[k-2]%MOD)*inv[n*k-i-(j-1)*(k-1)-k+1])%MOD;
         }
     }

     cout <<dp[n][n]*fac[n]%MOD<<"\n";
    return 0;
}

