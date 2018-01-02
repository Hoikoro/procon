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
    LL n,h;
    void solve(){
        cin >> n >> h;
        for(LL i=1; i<n; ++i){
            cout << pow(((double)i/n),(double)0.5)*(double)h <<' ';
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed<< setprecision(10) ;
    Problem p;
    p.solve();
    return 0;
}

