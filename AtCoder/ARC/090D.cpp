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
    vector<vector<pair<int,LL>>> a;
    vector<int> vis;
    vector<LL> ans,tmp;
    Problem(int n, int m):n(n),m(m),a(n),vis(n),ans(n){};
    void dfs(int i,LL x=0){
        DBG(i)
        if(vis[i] and x!= ans[i])no();
        if(!vis[i]){
            vis[i]=1;
            ans[i]=x;
            tmp.push_back(x);
            for(auto && j:a[i]){
                dfs(j.first,x+j.second);
            }
        }
    }
    void solve(){
        for(int i=0; i<m; ++i){
            LL l,r,d;
            cin >> l >> r >> d;
            --l,--r;
            a[l].emplace_back(r,d);
            a[r].emplace_back(l,-d);
        }
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                dfs(i);
                DBG(tmp)
                if(*max_element(tmp.begin(),tmp.end())-*min_element(tmp.begin(),tmp.end())>1e9)no();
                tmp.clear();
            }
        }
        cout << "Yes" << "\n";
    }
    void no(){cout << "No" <<"\n"; exit(0);}

};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0,m;
    std::cin >> n >> m;
    Solver::Problem p(n,m);
    p.solve();
    return 0;
}

