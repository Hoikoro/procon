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
    LL n,t;
    vector<LL> a;
    Problem(LL n):n(n),a(n){};

    void solve(){
        cin >> t;
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        a.push_back(LINF);
        LL ans=0;
        for(int i=0; i<n; ++i){
            ans+=min(t,a[i+1]-a[i]);
        }
        cout << ans <<"\n";

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

