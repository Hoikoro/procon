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
    LL n;
    string s;
    void solve(){
        cin >> s;
        n=s.length();
        LL ans =n*(n-1);
        for(int i=0; i<n; ++i){
            if(s[i]=='U'){
                ans+=i;
            }else{
                ans+=(n-1)-(i);
            }
            DBG(i,ans)
        }
        cout << ans <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    Problem p;
    p.solve();
    return 0;
}

