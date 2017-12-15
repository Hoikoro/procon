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
    LL n,sum;
    vector<LL> a;
    Problem(LL n):n(n),a(n){};

    void solve(){
        sum=0;
        for(int i=0; i<n; ++i){
            cin >> a[i];
            sum+=a[i];
        }
        LL t=a[0],ans=abs(sum-2*t);
        for(int i=1; i<n-1; ++i){
            t+=a[i];
            ans=min(ans,abs(sum-2*t));
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

