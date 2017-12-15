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
    Problem(LL n, LL m):n(n),m(m){};

    void solve(){
        if(n<=m){
            cout << n <<"\n";
            return;
        }
        //end of day m, n-m grain
        LL g=n-m,day=m;
        LL lb=0,ub=2e9;
        while(ub-lb>1){
            LL mid=(ub+lb)/2;
            if(mid*(mid+1)/2>=g)ub=mid;
            else lb=mid;
        }
        cout << ub+day <<"\n";

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

