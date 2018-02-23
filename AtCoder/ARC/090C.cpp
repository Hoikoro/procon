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
    int n;
    vector<vector<int>> a;
    Problem(LL n):n(n),a (2,vector<int>(n)){};

    void solve(){
        for(int i=0; i<2; ++i){
            for(int j=0; j<n; ++j){
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<n; ++i){
            int  tmp =0;
            for(int j=0; j<=i; ++j){
                tmp+=a[0][j];
            }
            for(int j=i; j<n; ++j){
                tmp+=a[1][j];
            }
            ans=max(ans,tmp);
        }
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

