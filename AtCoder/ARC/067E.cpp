#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#define DBG(...) {string dst__=#__VA_ARGS__;dreplace(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dreplace(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

VLL fac(1003),inv(1003);
long long modpow(long long a, long long n,long long mod=MOD){
    long long i=1,ret=1,p=a;
    while(i<=n){
        if(i&n) ret=(ret*p)%mod;
        i=(i<<1);
        p=(p*p)%mod;
    }
    return ret;
}
/*long long modpow(long long a, long long n){
    if(n==0) return 1;
    long long re=modpow((a*a)%MOD,n/2)%MOD;
    if(n%2==1) re= (re*a)%MOD;
    return re;
}*/

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    fac[0]=1; inv[0]=1;
    for(int i=1; i<1003; ++i){
        fac[i]=fac[i-1]*i%MOD;
    }
    inv[1002]=modpow(fac[1002],MOD-2);
    for(int i=1001; i>=1; --i){
        inv[i]=inv[i+1]*(i+1)%MOD;
    }
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >>d;
    vector<VLL> dp(n+1,VLL(n+1));
    dp[a-1][0]=1;
    for(int i=a; i<=b; ++i){
        dp[i][0]=1;
        for(int j=1; j<=n; ++j){
            if(j<n) dp[i][j]=dp[i-1][j];
            for(LL k=c; k<=min(d,j/i); ++k){
                LL den=((modpow(fac[i],k)*fac[k])%MOD*fac[n-j])%MOD;
                dp[i][j]=(dp[i][j]+(dp[i-1][j-i*k]*fac[n-j+i*k])%MOD*modpow(den,MOD-2))%MOD;
            }
        }
    }
    LL ans=0;
    for(int i=a; i<=b; ++i){
        ans=(ans+dp[i][n])%MOD;
    }
    cout <<ans <<"\n";

    return 0;
}

