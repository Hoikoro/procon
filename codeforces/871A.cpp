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
    int q;
    vector<LL> n;
    Problem(LL q):q(q),n(q){};

    void solve(){
        for(int i=0; i<q; ++i){
            cin >> n[i];
        }
        for(int i=0; i<q; ++i){;
            if(n[i]<=3 or (n[i]==5) or (n[i]==7) or (n[i]==11))cout << -1 <<"\n";
            else{
                int ans=0;
                if(n[i]%2==1){
                    n[i]-=9;
                    ++ans;
                }
                ans+=n[i]/4;
                cout << ans <<"\n";
            }

        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long q;
    cin >> q;
    Problem p(q);
    p.solve();
    return 0;
}

