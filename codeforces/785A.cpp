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
        LL ans = 0;
        for(int i=0; i<n; ++i){
            string tmp;
            cin >> tmp;
            if(tmp=="Tetrahedron") ans +=4;
            if(tmp=="Cube") ans +=6;
            if(tmp=="Octahedron") ans +=8;
            if(tmp=="Dodecahedron") ans +=12;
            if(tmp=="Icosahedron") ans +=20;
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

