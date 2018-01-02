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
    int n,l,p,m;
    vector<vector<int>> dist;
    vector<vector<pair<int,int>>> ld;
    vector<int> crim;
    vector<vector<vector<int>>> dp;
    Problem(LL n):n(n),l(0),dist (n,vector<int>(n,INF)){}; //<start,cnt,pos>

    void solve(){
        vector<int> cnt(n,0),leaf;
        for(int i=0; i<n; ++i){
            dist[i][i]=0;
        }
        for(int i=0; i<n-1; ++i){
            int a,b,w;cin >> a >> b >> w; --a;--b;
            dist[a][b]=dist[b][a]=w;
            cnt[a]++;cnt[b]++;
        }

        for(int i=0; i<n; ++i){
            if(cnt[i]==1){
                l++;
                leaf.push_back(i);
            }
        }
        ld = vector<vector<pair<int,int>>> (l);

        for(int k=0; k<n; ++k){
            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        for(int i=0; i<l; ++i){
            for(int j=0; j<l; ++j){
                ld[i].push_back({dist[leaf[i]][leaf[j]],j});
            }
        }
        for(int i=0; i<l; ++i){
            sort(ld[i].begin(),ld[i].end(),greater<pair<int,int>>());
        }

        cin >> p >> m;
        dp = vector<vector<vector<int>>> (l,vector<vector<int>>(m+1,vector<int>(l,INF)));
        for(int i=0; i<l; ++i){
            dp[i][0][i]=0;
        }
        DBG(ld)
        for(int j=1; j<m; ++j){
            for(int i=0; i<l; ++i){
                for(int k=0; k<l; ++k){
                    for(int h=0; h<l; ++h){
                        if(h==k)continue;
                        int catchnum=(j+l-1)/l;

                        //if(ld[h][j%l].first<dist[leaf[h]][leaf[k]])continue;
                        dp[i][j][k]=min(dp[i][j][k],dp[i][j-(j+l-1)/l][h]+dist[leaf[h]][leaf[k]]);
                    }
                }
            }
        }
        DBG(dp)
        --p;
        for(int i=0; i<m; ++i){
            int tmp; cin >> tmp; crim.push_back(tmp);
        }
        DBG(crim)
        int ans =INF;
        vector<pair<int,int>> d2;
        for(int i=0; i<l; ++i){
            if(leaf[i]!=p)d2.emplace_back(dist[p][leaf[i]],leaf[i]);
        }
        sort(d2.begin(),d2.end(),greater<pair<int,int>>());
        for(int i=0; i<l; ++i){
            for(int j=0; j<(int)d2.size(); ++j){
                if(d2[m%l].first<dist[p][leaf[j]]) continue;
                DBG(dp[i][m-1][j],dist[p][leaf[j]])
                ans=min(ans,dp[i][m-1][j]+dist[p][leaf[j]]);
            }
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

