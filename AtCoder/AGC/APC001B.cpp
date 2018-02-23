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
    LL sa,sb,cnt,sum;
    vector<LL> a,b;
    Problem(LL n):n(n),a(n),b(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        for(int i=0; i<n; ++i){
            cin >> b[i];
        }
        sa = accumulate(a.begin(),a.end(),0ll);
        sb = accumulate(b.begin(),b.end(),0ll);
        cnt = sb-sa;
        sum=0;
        for(int i=0; i<n; ++i){
            sum+=max((b[i]-a[i]+1)/2,0ll);
        }
        if(sum>cnt)cout << "No"<<"\n";
        else cout << "Yes" <<"\n";
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

