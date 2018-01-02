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
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
struct Problem{
    int n,m,sx,sy,gx,gy;
    vector<vector<char>> board;
    string s;
    Problem(LL n, LL m):n(n),m(m),board (n,vector<char>(m)){};

    void solve(){
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin >> board[i][j];
                if(board[i][j]=='S'){
                    sx=i,sy=j;
                }else if(board[i][j]=='E'){
                    gx=i,gy=j;
                }
            }
        }
        cin >> s;
        vector<int> dir ={0,1,2,3};
        int ans=0;
        do{
            int nx=sx,ny=sy;
            bool ok =false;
            for(int i=0; i<(int)s.size(); ++i){
                int xx=nx+dx[dir[s[i]-'0']];
                int yy=ny+dy[dir[s[i]-'0']];
                if(xx<0 or n<=xx or yy<0 or m<=yy or board[xx][yy]=='#'){
                    ok=false;
                    break;
                }
                if(board[xx][yy]=='E'){
                    ok=true;
                    break;
                }
                nx=xx;ny=yy;
            }
            if(ok)ans++;
        }while(next_permutation(dir.begin(),dir.end()));
        cout<< ans <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

