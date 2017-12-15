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
vector<LL> primes;
void sieve (LL n,vector<LL> &p){
    vector<char> isprime(n+1,1);
    //int cnt=0;
    isprime[0]=isprime[1]=0;
    for(LL i=2; i<=n; i++){
        if(isprime[i]){
            p.push_back(i);
            //++cnt;
            for(LL j=i*i; j<=n; j+=i) isprime[j]=0;
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    sieve(1100,primes);
    LL ans=1;
    for(int i=0; primes[i]<=n; ++i){
        LL tmp=0,now=n;
        while(now>1){
            tmp+=now/primes[i];
            now/=primes[i];
        }
        ans=ans*(tmp+1)%MOD;
    }
    cout << ans <<"\n";



    return 0;
}

