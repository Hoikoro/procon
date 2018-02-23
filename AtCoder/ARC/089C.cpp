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
    vector<int> x,y,t;
    Problem(LL n):n(n),x(n+1),y(n+1),t(n+1){};
    void solve(){
        for(int i=1; i<=n; ++i){
            cin >> t[i] >> x[i] >> y[i];
        }
        bool ans =true;
        for(int i=1; i<=n; ++i){
            int dist = abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
            int tt = t[i]-t[i-1];
            if(!(tt>=dist and(tt-dist)%2==0))ans =false;
        }
        if(ans)cout << "Yes" <<"\n";
        else cout << "No" << "\n";
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

