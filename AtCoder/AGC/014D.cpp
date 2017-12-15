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
using Graph = vector<vector<int>>;

struct Problem{
    int n;
    Graph g;
    vector<int> vwin, ewin;
    Problem(LL n):n(n),g(n),vwin(n),ewin(n){};
    void dfs(int prev, int cur){
        DBG(prev,cur)
        if((int)g[cur].size()==1 and g[cur][0]==prev){
            vwin[cur]=1;
        DBG(cur,vwin[cur],ewin[cur])
            return;
        }
        vwin[cur]=1;
        int tmp=0;
        for(auto &x : g[cur]){
            if(x!=prev){
                dfs(cur,x);
                if(vwin[x]==1)ewin[cur]=1,tmp++;
                if(ewin[x]==0)vwin[cur]=0;
            }
        }
        if(tmp>=2)vwin[cur]=1;
        DBG(cur,vwin[cur],ewin[cur])
    }
    void solve(){
        for(int i=0; i<n-1; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        dfs(-1,0);
        if(vwin[0])cout <<"First"<<"\n";
        else cout << "Second" << "\n";
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

