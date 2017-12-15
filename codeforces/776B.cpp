#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#include "lib/mydebug.h"
#else
#define DBG(...) ;
#endif
using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

struct Problem{
    int n;
    vector<int> a,isprime;
    Problem(LL n):n(n),a(n),isprime(n+2,1){};
    void sieve (LL n){
        isprime[0]=isprime[1]=0;
        for(LL i=2; i<=n; i++){
            if(isprime[i]){
                for(LL j=i*i; j<=n; j+=i) isprime[j]=0;
            }
        }
    }
    void solve(){
        sieve(n+1);
        DBG(n)
        if(n<=2){
            cout << 1 <<"\n";
            for(int i=0; i<n; ++i){
                cout << 1 <<' ';
            }
            cout <<"\n";
        }else {
            cout <<2 <<"\n";
            for(int i=2; i<=n+1; ++i){
                if(isprime[i])cout << 1 <<' ';
                else cout << 2 <<' ';
            }
            cout <<"\n";
        }
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

