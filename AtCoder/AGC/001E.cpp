#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dbgsplit(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...) ;
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dbgsplit(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}
using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;
struct Problem{
    int n;
    vector<int> a,b;
    const int nn=4004;
    vector<vector<LL>> _dp;
    Problem(LL n):n(n),a(n),b(n),_dp(nn,vector<LL>(nn)){};
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
        vector<LL> fac(2*nn);
        fac[0]=1;
        for(int i=1; i<(int)fac.size(); ++i){
            fac[i]=fac[i-1]*i%MOD;
        }
        auto dp = [&](int x, int y) -> auto& {return _dp[x+2001][y+2001];};
        for(int i=0; i<n; ++i){
            cin >> a[i] >> b[i];
            dp(-a[i],-b[i])++;
        }
        for(int i=-2000; i<=2000; ++i){
            for(int j=-2000; j<=2000; ++j){
                dp(i,j)=(dp(i,j)+dp(i-1,j)+dp(i,j-1))%MOD;
            }
        }
        LL ans =0;
        for(int i=0; i<n; ++i){
            ans=(ans+dp(a[i],b[i]))%MOD;
        }
        for(int i=0; i<n; ++i){
            LL to_self=(fac[a[i]*2+b[i]*2]*modpow(fac[a[i]*2],MOD-2)%MOD)*modpow(fac[b[i]*2],MOD-2)%MOD;
            ans=(ans- to_self+MOD)%MOD;
        }
        cout << ans*modpow(2,MOD-2)%MOD <<"\n";
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;

    Problem p(n);
    p.solve();
    return 0;
}

