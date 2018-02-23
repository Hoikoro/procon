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
    LL n,mini,maxi;
    vector<LL> a;
    Problem(LL n):n(n),a(n){};

    void solve(){
        for(int i=0; i<n; ++i){
             cin >> a[n-1-i];
        }
        mini=maxi=2;
        for(int i=0; i<n; ++i){
            mini = (mini+a[i]-1)/a[i]*a[i];
            maxi = (maxi/a[i]+1)*a[i]-1;
            if(mini>maxi)no();
        }
        cout << mini <<' '<<maxi <<"\n";
    }
    void no (){cout <<-1 <<"\n"; exit(0);}
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

