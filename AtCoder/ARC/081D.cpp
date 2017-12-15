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
    Problem(LL n):n(n){};

    void solve(){
        vector<string> s(2);
        for(int i=0; i<2; ++i){
            cin >> s[i];
        }
        LL ans =1,prev=0;
        for(int i=0; i<n; ++i){
            if(s[0][i]==s[1][i]){
                ans=(ans*(3ll-prev))%MOD;
                prev=1;
            }else{
                if(prev==0){
                    ans=(ans*6ll)%MOD;
                }else if(prev==1){
                    ans=(ans*2ll)%MOD;
                }else{
                    ans=(ans*3ll)%MOD;
                }
                prev=2;
                ++i;
            }
        }
        cout << ans << "\n";
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

