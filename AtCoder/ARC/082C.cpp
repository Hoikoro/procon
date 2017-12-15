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
    LL n,s;
    vector<LL> c;
    Problem(LL n):n(n),s(100000),c(s){};

    void solve(){
        for(int i=0; i<n; ++i){
            int tmp;
            cin >> tmp;
            c[tmp]++;
        }
        int ans =0;
        for(int i=1; i<=1e5-2; ++i){
            ans = max<int>(ans,c[i-1]+c[i]+c[i+1]);
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

