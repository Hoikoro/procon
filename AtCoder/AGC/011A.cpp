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
    int n,c,k;
    vector<int> t;
    Problem(LL n):n(n),t(n){};

    void solve(){
        cin >> c >> k;
        for(int i=0; i<n; ++i){
            cin >> t[i];
        }
        sort(t.begin(),t.end());
        int ans=0,pos=0;
        for(; pos<(int)t.size();++ans){
            pos=min<int>(pos+c,upper_bound(t.begin(),t.end(),t[pos]+k)-t.begin());
        }
        cout <<ans <<"\n";
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

