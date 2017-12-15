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
    LL n,m;
    vector<LL> fac;
    Problem(LL n,LL m):n(n),m(m),fac(1e5+1){};

    void solve(){
        fac[0]=1;
        for(int i=1; i<=1e5; ++i){
            fac[i]=fac[i-1]*i%MOD;
        }
        if(abs(n-m)>1)cout << 0 <<"\n";
        else if (n==m)cout << fac[n]*fac[m]*2%MOD <<"\n";
        else cout << fac[n]*fac[m]%MOD <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

