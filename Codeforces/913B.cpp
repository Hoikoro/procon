#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;


namespace Solver{
#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif
using namespace std;
struct Problem{
    int n;
    vector<vector<int>> t;
    bool ans;
    Problem(LL n):n(n),t(n),ans(true){};

    void solve(){
        for(int i=1; i<n; ++i){
            int a;
            cin >> a;
            --a;
            t[a].push_back(i);
        }
        dfs(0);
        if(ans)cout << "Yes" << "\n";
        else cout << "No" <<"\n";
    }
    int dfs(int c){
        if(t[c].empty())return 1;
        int cnt = 0;
        for(auto && v :t[c]){
            cnt+=dfs(v);
        }
        if(cnt<3)ans=false;
        return 0;
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0;
    std::cin >> n;
    Solver::Problem p(n);
    p.solve();
    return 0;
}

