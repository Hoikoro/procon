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
    string s;
    void solve(){
        cin >> s;
        string v="13579aeiou";
        int ans =0;
        for(int i=0; i<(int)s.size(); ++i){
            for(int j=0; j<10; ++j){
                if(s[i]==v[j]){
                    ans++;
                }
            }
        }
        cout <<ans <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Problem p;
    p.solve();
    return 0;
}

