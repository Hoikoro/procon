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
    vector<vector<int>> g;
    vector<vector<pair<int,int>>> col,now;
    Problem(LL n, LL m):n(n),m(m),g(n),col (n,vector<pair<int,int>>(11,{-1,0})),now (n,vector<pair<int,int>>(11,{-1,0})){};

    void solve(){
        for(int i=0; i<m; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cin >> q;
        for(int i=0; i<q; ++i){
            int v,c,d;
            cin >> v >> d >> c;
            --v;
            col[v][d]={i,c};
        }
        for(int i=0; i<10; ++i){
            for(int j=0; j<n; ++j){
                for(int l=10-i; l>=1; --l){
                    if(col[j][l].first > col[j][l-1].first){
                        col[j][l-1]=col[j][l];
                    }
                }
                for(auto && v:g[j]){
                    for(int l=10-i; l>=1; --l){
                        if(col[j][l].first > col[v][l-1].first){
                            col[v][l-1]=col[j][l];
                        }
                    }
                }
            }
        }
        for(int i=0; i<n; ++i){
            cout << col[i][0].second<<endl;
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

