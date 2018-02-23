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
    LL x,y;
    void solve(){
        cin >> x >> y;
        if(x%y==0){
            cout << -1 <<"\n";
        }else{
            LL i = 1;
            while(1){
                if((x*i)%y!=0){
                    cout << x*i <<"\n";
                    break;
                }
            }
        }
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    Solver::Problem p;
    p.solve();
    return 0;
}

