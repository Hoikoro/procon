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
    LL n,weight;
    vector<LL> v,w;
    Problem(LL n):n(n),v(n),w(n){};

    void solve(){
        cin >> weight;
        for(int i=0; i<n; ++i){
            cin >> w[i] >> v[i];
        }
        unordered_map<LL,LL> dp;
        dp[0]=0;
        for(int i=0;i<n;i++){
            vector<pair<LL,LL>> add;
            for(auto &j : dp){
                if(j.first+w[i]<=weight){
                    add.emplace_back(j.first+w[i],j.second+v[i]);
                }
            }
            for(auto &j : add){
                dp[j.first]=max(dp[j.first],j.second);
            }
        }
        LL ans = 0;
        for(auto &x : dp){
            DBG(x)
            if(x.first<=weight)ans = max(ans, x.second);
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

