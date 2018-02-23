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
    vector<int> p;
    void solve(){
        cin >> s;
        p.push_back(0);
        for(int i=1; i<(int)s.size(); ++i){
            if(s[i]!=s[i-1])p.push_back(i);
        }
        int ans = INF;
        for(auto && i : p){
            ans=min(ans,max((int)s.size()-i,i));
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

