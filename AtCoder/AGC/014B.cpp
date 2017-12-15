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
    int n,m;
    vector<int> cnt;
    Problem(LL n, LL m):n(n),m(m),cnt(n){};

    void solve(){
        for(int i=0; i<m; ++i){
            int s,t;
            cin >> s >> t;
            --s;--t;
            ++cnt[s];++cnt[t];
        }
        bool ans=true;
        for(int i=0; i<n; ++i){
           if(cnt[i]%2==1)ans=false;
        }
        cout << (ans?"YES":"NO") <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

