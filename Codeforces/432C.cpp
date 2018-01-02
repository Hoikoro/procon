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
    LL n;
    vector<LL> a,nm;
    vector<LL> primes;
    vector<vector<pair<LL,int>>> pf;
    Problem(LL n):n(n),a(n),pf(n){};
    vector<char> sieve (LL n,vector<LL> &p){
        vector<char> isprime(n+1,1);
        //int cnt=0;
        isprime[0]=isprime[1]=0;
        for(LL i=2; i<=n; i++){
            if(isprime[i]){
                primes.push_back(i);
                //++cnt;
                for(LL j=i*i; j<=n; j+=i) isprime[j]=0;
            }
        }
        return isprime;
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
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        sieve(1e5,primes);
        for(int i=0; i<n; ++i){
            DBG(i)
            pf[i]=primeFactor(a[i]);
            DBG(pf)
        }
        for(int i=0; i<n; ++i){
            DBG(i)
            for(int j=0; j<(int)pf[i].size(); ++j){
                nm.push_back(pf[i][j].second);
            }
        }
        LL ans =0;
        for(int i=0; i<(int)nm.size(); ++i){
            ans=ans^nm[i];
        }
        if(ans==0)cout << "Arpa"<<"\n";
        else cout << "Mojtaba"<<"\n";
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

