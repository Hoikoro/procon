#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;


namespace Solver{
#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif
using namespace std;
struct Problem{
    LL  n,m;
    Problem(LL n, LL m):n(n),m(m){};
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
        if(n>=29){
            cout << m <<"\n";
        }else{
            n = modpow(2,n);
            cout << m%n <<"\n";
        }
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0,m;
    std::cin >> n >> m;
    Solver::Problem p(n,m);
    p.solve();
    return 0;
}

