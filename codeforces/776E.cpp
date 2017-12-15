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
    LL n,k;
    vector<LL> primes;
    void sieve (LL n){
        vector<char> isprime(n+1,1);
        isprime[0]=isprime[1]=0;
        for(LL i=2; i<=n; i++){
            if(isprime[i]){
                primes.push_back(i);
                for(LL j=i*i; j<=n; j+=i) isprime[j]=0;
            }
        }
    }
    vector<pair<long long ,int>> primeFactor(long long k){
        LL div=1;
        vector<pair<long long ,int>> ret;
        for(int i=0; ;++i){
            if(primes[i]*primes[i]>k){
                if(div!=k)ret.push_back(make_pair(k/div,1));
                break;
            }
            if(k%primes[i]==0){
                ret.push_back(make_pair(primes[i],0));
                LL kk=k;
                while(kk%primes[i]==0){
                    kk/=primes[i];
                    div*=primes[i];
                    (ret.end()-1)->second++;
                }
            }
        }
        return ret;
    }
    void solve(){
        cin >> n >> k;
        LL ans = n;
        sieve(2e6);
        LL loop = (k+1)/2;
        for(int i=0; i<loop && ans >1; ++i){
            vector<pair<LL,int>> pf=primeFactor(ans);
            if(pf.size()==1 and pf[0].second==1){
                --ans;
            }else{
                for(auto p: pf){
                    DBG(p.first,p.second)
                ans=ans/p.first*(p.first-1ll);
                }
            }
            DBG(ans)
        }
        cout << ans%MOD <<"\n";
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Problem p;
    p.solve();
    return 0;
}

