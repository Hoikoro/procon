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
    vector<int> t,c;
    Problem(LL n):n(n),t(n+1),c(n+1){};

    void solve(){
        int ans =1;
        for(int i=1; i<=n; ++i){
            cin >> t[i];
        }
        c[0]=1;
        for(int i=1; i<=n; ++i){
            if(c[t[i]]==1){
                c[t[i]]=0;
                c[i]=1;
            }else{
                ans++;
                c[i]=1;
            }
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

