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
    int h,w,k,sx,sy;
    vector<vector<char>> b;
    vector<vector<int>> dist;
    Problem(LL h, LL w):h(h),w(w),b(h,vector<char>(w)), dist (h,vector<int>(w,-1)){};
    void solve(){
        cin >> k;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cin >> b[i][j];
                if(b[i][j]=='S'){
                    sx=i,sy=j;
                }
            }
        }
        int ans =INF;
        queue<pair<int,int>> Q;
        Q.push({sx,sy});
        dist[sx][sy]=0;
        int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
        while(!Q.empty()){
            int x=Q.front().first;
            int y= Q.front().second;
            Q.pop();
            int st=min({x,y,h-x-1,w-y-1});
            int step;
            if(dist[x][y]<=k){
                step=(st+k-1)/k+1;
            }else{
                step=(dist[x][y]+st+k-1)/k;
            }
            DBG(x,y,st,step)
            ans=min(ans,step);
            for(int i=0; i<4; ++i){
                if(x+dx[i]>=0 and x+dx[i]<h and y+dy[i]>=0 and y+dy[i]<w and b[x+dx[i]][y+dy[i]]=='.' and dist[x+dx[i]][y+dy[i]]<0){
                    dist[x+dx[i]][y+dy[i]]=dist[x][y]+1;
                    DBG(x+dx[i],y+dy[i],dist[x+dx[i]][y+dy[i]])
                    Q.push({x+dx[i],y+dy[i]});
                }
            }
        }
        cout << ans <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long h=0,w;
    cin >> h >>w;
    Problem p(h,w);
    p.solve();
    return 0;
}

