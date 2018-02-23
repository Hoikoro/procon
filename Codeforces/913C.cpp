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
    LL n,d;
    vector<LL> cost;
    Problem(LL n):n(n),cost(30,LINF){};

    void solve(){
        cin >> d;
        for(int i=0; i<n; ++i){
            cin >> cost[i];
        }
        for(int i=1; i<30; ++i){
            cost[i]=min(cost[i],cost[i-1]*2);
        }
        LL ans =LINF,sum=0;
        DBG(cost,ans)
        for(int i=29; i>=0; --i){
            if((d>>i)&1)sum+=cost[i];
            ans=min(ans,sum+cost[i]);
            DBG(sum,ans)
        }
        ans=min(ans,sum);
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

