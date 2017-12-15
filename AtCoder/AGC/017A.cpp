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
    LL n,p;
    Problem(LL n):n(n){};

    void solve(){
        vector<int> c(2);
        cin >> p;
        for(int i=0; i<n; ++i){
            int tmp;
            cin >> tmp;
            c[tmp%2]++;
        }
        if(p==1){
            if(c[1]==0)cout << 0 << "\n";
            else cout << (1ll<<(c[0]+c[1]))/2<<"\n";
        }else{
            if(c[1] == 0)cout << (1ll<<(c[0]+c[1])) <<"\n";
            else cout << (1ll<<(c[0]+c[1]))/2 <<"\n";
        }
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

