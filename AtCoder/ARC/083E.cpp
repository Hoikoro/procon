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
    int n;
    vector<int> x,p,dp;
    vector<vector<int>> ch;
    Problem(LL n):n(n),x(n),p(n),dp(n),ch(n){};
    void fail() {cout << "IMPOSSIBLE"<< "\n"; exit(0);};
    void solve(){
        for(int i=1; i<n; ++i){
            cin >> p[i];
            p[i]--;
            ch[p[i]].push_back(i);
        }
        for(int i=0; i<n; ++i){
            cin >> x[i];
        }
        dfs(0);
        DBG(dp)
        cout << "POSSIBLE"<<"\n";
    }
    void dfs(int cur){
        if((int)ch[cur].size()==0){
            return;
        }
        vector<int> tmp(x[cur]+1);
        tmp[0]=1;
        LL sum =0;
        for(auto &&y: ch[cur]){
            vector<int> tmp2(x[cur]+1);
            dfs(y);
            sum+=dp[y]+x[y];
            for(int i=0; i<(int)tmp.size(); ++i){
                if((i>=dp[y] and tmp[i-dp[y]]>0)or(i>=x[y] and tmp[i-x[y]]>0)) tmp2[i]=1;
            }
            tmp.swap(tmp2);
        }
        for(int i=(int)tmp.size()-1; i>=0; --i){
            if(tmp[i]>0){
                dp[cur]=sum-i;
                break;
            }
            if(i==0)fail();
        }
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

