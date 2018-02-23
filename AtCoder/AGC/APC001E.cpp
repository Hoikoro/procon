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
    int n,ans;
    vector<vector<int>> t;
    vector<int> cnt,need;
    Problem(LL n):n(n),ans(0),t(n),cnt(n),need(n){};
    void dfs(int c,int p =-1){
        if(p==-1){
            dfs(t[c][0],c);
            DBG(t[c][0],need[t[c][0]])
            if(need[t[c][0]]){
                DBG(c,ans)
                ans++;
            }
        }else if ((int)t[c].size()==2){
            for(int i=0; i<2; ++i){
                if(t[c][i]!=p){
                    dfs(t[c][i],c);
                    cnt[c]=cnt[t[c][i]];
                    need[c]=need[t[c][i]];
                }
            }
        }else if ((int)t[c].size()==1){
            need[c]=1;
        }else{
            int tmp=0,op=0,e=0;
            for(auto v:t[c])if(v!=p){
                dfs(v,c);
                if(cnt[v]==0)tmp++;
                else op++,e=v;
                cnt[c]+=cnt[v];
            }
            /*if(op==0){
                ans+=tmp-1;
                cnt[c]+=tmp-1;
                need[c]=1;
            }
            if(op>=2 and tmp==0){

            }
            if(op==1 and tmp==1){
                need[c]=1;
            }
            if(op>=2 and tmp==1){
                need[c]=1;
            }
            if(op==1 and tmp>=2){
                ans+=tmp-1;
                cnt[c]+=tmp-1;
                need[c]=1;
            }
            if(op>=2 and tmp>=2){
                ans+=tmp-1;
                cnt[c]+=tmp-1;
                need[c]=1;
            }*/
            if(tmp>=1)need[c]=1;
            if(tmp>=2){
                ans+=tmp-1;
                cnt[c]+=tmp-1;
                need[c]=1;
            }

            /*if(tmp>1){
                DBG(c,ans)
                ans+=tmp-1;
                cnt[c]+=tmp-1;
            }
            if(cnt[c]==1){
                need[c]=1;
            }*/
            DBG(c,ans)
        }
    }
    void solve(){
        for(int i=0; i<n-1; ++i){
            int a,b;
            cin >> a >>b;
            t[a].push_back(b);
            t[b].push_back(a);
        }
        int root=0;
        for(int i=0; i<n; ++i){
            if((int)t[i].size()==1){
                root = i;
                break;
            }
        }
        DBG(root)
        dfs(root);
        cout << ans <<"\n";
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

