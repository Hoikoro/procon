#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;
#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif


namespace Solver{
using namespace std;

struct Problem{
    int n,sum;
    vector<int > a,dp;
    Problem(LL n):n(n),sum(0),a(n){};

    void solve(){
        for(int i=0; i<n; ++i){
             cin >> a[i];
             sum+=a[i];
        }
        bitset<4000001> dp;
        dp.set(0);
        for(int i=0; i<n; ++i){
            dp|=(dp<<a[i]);
        }
        int ans = (sum+1)/2;
        while(!dp[ans])ans++;
        cout << ans <<"\n";
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0;
    std::cin >> n;
    Solver::Problem p(n);
    p.solve();
    return 0;
}

