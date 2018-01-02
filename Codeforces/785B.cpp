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
    int n,m;
    void solve(){
        cin >> n;
        int lc=0,rc=INF,lp=0,rp=INF;
        for(int i=0; i<n; ++i){
            int a,b;
            cin >> a >> b;
            lc=max(lc,a);
            rc=min(rc,b);
        }
        cin >> m;
        for(int i=0; i<m; ++i){
            int a,b;
            cin >> a >> b;
            lp=max(lp,a);
            rp=min(rp,b);
        }
        cout << max({0,lc-rp,lp-rc}) <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;

    Problem p;
    p.solve();
    return 0;
}

