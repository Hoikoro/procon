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
    LL k;
    Problem(LL k):k(k){};

    void solve(){
        cout << 50 <<"\n";
        vector<LL> ans(50,49);
        for(int i=0; i<50; ++i){
            ans[i]+=k/50;
        }
        for(int i=0; i<k%50; ++i){
            for(int j=0; j<50; ++j){
                if(j==i)ans[j]+=50;
                else ans[j]--;
            }
        }
        for(int i=0; i<50; ++i){
            cout << ans[i];
            if(i<49)cout << ' ';
        }
        cout <<"\n";
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

