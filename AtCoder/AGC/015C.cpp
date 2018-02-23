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
    int n,m,q;
    vector<vector<int>> s,h,v;
    Problem(LL n ,LL m):n(n),m(m),s (n+1,vector<int>(m+1)),h (n+1,vector<int>(m+1)),v(n+1,vector<int>(m+1)){};

    void solve(){
        cin >> q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                char tmp;
                cin >> tmp;
                s[i+1][j+1]=tmp-'0';
            }
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m-1; ++j){
                if(s[i][j] and s[i][j+1]){
                    h[i][j+1]=1;
                }
            }
        }
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n-1; ++j){
                if(s[j][i] and s[j+1][i]){
                    v[j+1][i]=1;
                }
            }
        }
        for(int i=0; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                s[i][j]+=s[i][j-1];
                h[i][j]+=h[i][j-1];
                v[i][j]+=v[i][j-1];
            }
        }
        for(int i=0; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                s[j][i]+=s[j-1][i];
                h[j][i]+=h[j-1][i];
                v[j][i]+=v[j-1][i];
            }
        }
        for(int i=0; i<q; ++i){
            int a,b,c,d,ans=0;
            cin >> a >> b >> c >> d;--a;--b;
            ans+=s[c][d]-s[a][d]-s[c][b]+s[a][b];
            ans-=h[c][d]-h[a][d]-h[c][b+1]+h[a][b+1];
            ans-=v[c][d]-v[a+1][d]-v[c][b]+v[a+1][b];
            cout << ans <<"\n";
        }
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

