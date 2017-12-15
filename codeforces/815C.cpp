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
    LL n,b;
    vector<vector<int>> t;
    vector<vector<pair<int,int>>> sort_t;
    vector<vector<LL>> dpo,dpx;
    vector<LL> c,d;
    vector<int>cnt;
    Problem(LL n,LL b):n(n),b(b),t(n),sort_t(n),dpo(n,vector<LL>(n+1,LINF)),dpx(n,vector<LL>(n+1,LINF)),c(n),d(n),cnt(n){};
    void predfs(int par , int cur){
        if((int)t[cur].size()==0){
            cnt[cur]=1;
            return;
        }
        for(int x: t[cur]){
            predfs(cur,x);
            cnt[cur]+=cnt[x];
            sort_t[cur].emplace_back(cnt[x],x);
        }
        cnt[cur]+=1;
    }
    void dfs(int par,int cur){
        if((int)t[cur].size()==0){
            dpo[cur].resize(2);
            dpx[cur].resize(2);
            dpo[cur]={LINF,d[cur]};
            dpx[cur]={0,c[cur]};
            return;
        }
        bool fi=true;
        int child=0;
        for(int i=0;i<(int)t[cur].size();++i){
            int x= t[cur][i];
            child+=cnt[x];
            if(fi){
                dfs(cur,x);
                dpo[cur]=dpo[x];
                dpx[cur]=dpx[x];
                dpo[cur].resize(child+2);
                dpx[cur].resize(child+2);
                for(int i=cnt[x]+1; i<dpo[cur].size(); ++i){
                    dpo[cur][i]=LINF;
                    dpx[cur][i]=LINF;
                }
                fi=false;
            }else{
                dfs(cur,x);
                dpo[cur]=convo(cur,x,child+1);
                dpx[cur]=conv(dpx[cur],dpx[x],child+1);
            }
        }
        for(int i=cnt[cur]; i>=1; --i){
            dpo[cur][i]=min(dpo[cur][i-1]+d[cur],dpx[cur][i-1]+d[cur]);
            dpx[cur][i]=min(dpx[cur][i-1]+c[cur],dpx[cur][i]);
        }
    }
    vector<LL> convo(int a, int b,int s){
        vector<LL> ret(s+1,LINF);
        for(int i=0; i<(int)dpo[a].size(); ++i){
            for(int j=0; j<(int)dpo[b].size() && i+j<=s; ++j){
                ret[i+j]=min({ret[i+j],dpo[a][i]+dpx[b][j],dpo[a][i]+dpo[b][j],dpx[a][i]+dpo[b][j]});
            }
        }
        return ret;
    }
    vector<LL> conv(vector<LL> &a, vector<LL> &b,int s){
        vector<LL> ret(s+1,LINF);
        for(int i=0; i<(int)a.size(); ++i){
            for(int j=0; j<(int)b.size() && i+j<=s; ++j){
                ret[i+j]=min(ret[i+j],a[i]+b[j]);
            }
        }
        return ret;
    }
    void solve(){
        for(int i=0; i<n; ++i){
            dpo[i][0]=0;
            dpx[i][0]=0;
        }
        cin >> c[0] >> d[0];
        d[0]=c[0]-d[0];
        for(int i=1; i<n; ++i){
            int tmp;
            cin >> c[i] >> d[i] >> tmp;
            d[i]=c[i]-d[i];
            --tmp;
            t[tmp].push_back(i);
        }
        predfs(-1,0);
        for(int i=0; i<n; ++i){
            sort(sort_t[i].begin(),sort_t[i].end());
            for(int j=0; j<(int)sort_t[i].size(); ++j){
                t[i][j]=sort_t[i][j].second;
            }
        }
        dfs(-1,0);
        LL ans =n;
        for(int i=1; i<=n; ++i){
            if(dpx[0][i]>b and dpo[0][i]>b){
                ans=i-1;
                break;
            }
        }
        cout << ans <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,b;
    cin >> n >> b;
    Problem p(n,b);
    p.solve();
    return 0;
}