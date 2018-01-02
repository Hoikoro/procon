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
    int n;
    int r;
    vector<double> x,ans;
    vector<double> c_;
    Problem(LL n):n(n),x(n),ans(n),c_(10000,-3333){};

    void solve(){
        auto c = [&](int x) -> auto& {return c_[x+3333];};

        cin >> r;
        for(int i=0; i<n; ++i){
            cin >> x[i];
        }
        for(int i=0; i<n; ++i){
            ans[i]=r;
            for(int j=x[i]-2*r; j<=x[i]+2*r; ++j){
                ans[i]=max(ans[i],c(j)+sqrt(4.0*r*r-(x[i]-j)*(x[i]-j)));
            }
            c(x[i])=ans[i];
            cout << ans[i] <<' ';
        }

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cout << fixed <<setprecision(20);
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

