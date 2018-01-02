#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

string dst__; stringstream dss__;
#define DBG(...) dst__=#__VA_ARGS__;myreplace(dst__);dss__.str("");dss__.clear(stringstream::goodbit); dss__<<dst__; debug(dss__,__VA_ARGS__);
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void myreplace(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

void sieve (LL n,vector<LL> &p){
    vector<char> isprime(n+1,1);
    isprime[0]=isprime[1]=0;
    for(LL i=2; i<=n; i++){
        if(isprime[i]){
            p.push_back(i);
            for(LL j=i*i; j<=n; j+=i) isprime[j]=0;
        }
    }
}
vector<LL> primes;
vector<VLL> dp(22,VLL(1000010));
LL r,c;

LL primeFactor(long long k){
    vector<pair<long long ,int>> ret;
    for(int i=0; ;++i){
        if(primes[i]*primes[i]>k){
            if(k!=1ll)ret.push_back(make_pair(k,1));
            break;
        }
        if(k%primes[i]==0){
            ret.push_back(make_pair(primes[i],0));
            while(k%primes[i]==0){
                k/=primes[i];
                ret.back().second++;
            }
        }
    }
    LL ans=1;
        for(auto &y : ret){
            ans=ans*dp[y.second][r]%MOD;
        }
    return ans;
}

int main(){
    //cin.tie(0);
    //ios_base::sync_with_stdio(false);
    sieve(1000003,primes);
    for(int i=1; i<22; ++i){
        dp[i][0]=2;
        if(i==1){
            for(int j=1; j<1000010; ++j){
                dp[i][j]=j+2;
            }
        }else{
            for(int j=1; j<1000010; ++j){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]%MOD;
            }
        }
    }
    int  n;
    cin >>n;
    for(int i=0; i<n; ++i){
        scanf("%lld%lld",&r,&c);
        auto ans = primeFactor(c);

        printf("%lld\n",ans);
    }



    return 0;
}

