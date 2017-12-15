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
    vector<LL> a,sum;
    Problem(LL n):n(n),a(n+1),sum(n+1){};

    void solve(){
        for(int i=1; i<=n; ++i){
            cin >>a[i];
        }
        sort(a.begin(),a.end());
        for(int i=1; i<=n; ++i){
            sum[i]=sum[i-1]+a[i];
        }
        int pos=n-1;
        for(;;--pos){
            if(sum[pos]*2<a[pos+1])break;
        }
        cout << n-pos <<"\n";
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

