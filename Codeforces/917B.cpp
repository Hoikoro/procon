#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;
#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif


namespace Solver{
using namespace std;

struct Problem{
    int n,m;
    vector<vector<pair<int,int>>> g;
    vector<vector<vector<int>>> memo;
    Problem(LL n, LL m):n(n),m(m),g(n),memo (n,vector<vector<int>>(n,vector<int>(26,-1))){};

    void solve(){
        for(int i=0; i<m; ++i){
            int a,b;char c;
            cin >> a >> b >> c;
            --a;--b;
            g[a].emplace_back(b,c-'a');
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(calc(i,j,0)>0)cout << 'A';
                else cout << 'B';
            }
            cout << "\n";
        }
    }
    int calc(int i, int j, int c){
        DBG(i,j,c)
        if(memo[i][j][c]>=0)return memo[i][j][c];
        int ret = 0;
        set<int> res;
        for(auto x:g[i]){
            if(x.second>=c){
                res.insert(calc(j,x.first,x.second));
            }
        }
        while(res.find(ret)!=res.end())ret++;
        return memo[i][j][c]=ret;
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0,m;
    std::cin >> n>>m;
    Solver::Problem p(n,m);
    p.solve();
    return 0;
}

