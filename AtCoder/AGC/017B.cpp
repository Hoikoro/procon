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
    LL n,a,b,c,d;

    void solve(){
        cin >> n >> a >> b >> c >> d;
        for(int i=0; i<n; ++i){
            LL u = d*i-c*(n-1-i);
            LL l = c*i-d*(n-1-i);
            if(l<=b-a and b-a <=u){
                cout << "YES" << "\n";
                return;
            }
        }
        cout << "NO" << "\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    Problem p;
    p.solve();
    return 0;
}

