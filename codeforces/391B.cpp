#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

string dst__; stringstream dss__;
#define DBG(...) dst__=#__VA_ARGS__;replace(dst__.begin(),dst__.end(),',',' ');dss__.str("");dss__.clear(stringstream::goodbit); dss__<<dst__; debug(dss__,__VA_ARGS__);
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

void sieve (LL n,vector<LL> &p){
    vector<int> isprime(n+1,1);
    isprime[0]=isprime[1]=0;
    for(LL i=2; i<=n; i++){
        if(isprime[i]){
            p.push_back(i);
            for(LL j=i*i; j<=n; j+=i) isprime[j]=0;
        }
    }
}

vector<LL> primes;

void primeFactor(LL k, map<LL,int> &m){
    LL div=1;
    vector<pair<LL ,int>> ret;
    for(LL i=0; ;++i){
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
    for(auto p : ret){
        m[p.first]++;
    }
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    sieve(100010,primes);
    int n;
    cin >> n;
    VI s(n);
    map<LL,int> p;
    for(int i=0; i<n; ++i){
        cin >> s[i];
        primeFactor(s[i],p);
    }

    int ans=0;
    for(auto x:p){
        ans=max(ans,x.second);
    }
    cout << max(1,ans) <<endl;



    return 0;
}