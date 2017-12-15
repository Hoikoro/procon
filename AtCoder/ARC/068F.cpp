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
vector<long long> fac(3030),two(3030),inv(3030);

LL modcomb(LL a, LL b){
    if(a==0 and b==-1){
        return 1;
    }else if(a<b){
        return 0;
    }else{
        return (fac[a]*inv[b]%MOD)*inv[a-b]%MOD;
    }
}
LL pow2(LL a){
    if(a==-1)return 1;
    else return two[a];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    fac[0]=1;
    two[0]=1;
    const int lim=3030;
    for(int i=1; i<lim; ++i){
        fac[i]=fac[i-1]*i%MOD;
        two[i]=two[i-1]*2%MOD;
    }
    inv[lim-1]=modpow(fac[lim-1],MOD-2);
    for(int i=lim-2; i>=0; --i){
        inv[i]=inv[i+1]*(i+1)%MOD;
    }

    vector<vector<LL>> dp (k+1,vector<LL>(k+1));
    for(int i=1; i<k; ++i){
        dp[k-1][i]=1;
    }
    for(int i=k-2; i>=1; --i){
        dp[i][1]=(dp[i+1][1]+dp[i+1][2])%MOD;
        for(int j=2; j<=i; ++j){
            //dp[i][j]=sum(dp[i+1][1]~dp[i+1][j+1])
            dp[i][j]=(dp[i][j-1]+dp[i+1][j+1])%MOD;
        }
    }
    dp[0][0]=dp[1][1];
    LL ans=0;
    if(k==1){
        cout << pow2(n-2)<<"\n";
        return 0;
    }else if(k==n){
        ans=dp[0][0]%MOD;
    }else{
        for(int m=n; m>=n-k+1; --m){
            ans=(ans+((modcomb(m-2,n-k-1)*pow2(n-k-1)%MOD)*dp[m-(n-k+1)][m-(n-k+1)])%MOD)%MOD;
        }
    }

    cout << ans <<"\n";
    return 0;
}

