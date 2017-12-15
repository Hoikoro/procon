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
    LL n,m;
    vector<LL> x,y;
    Problem(LL n, LL m):n(n),m(m),x(n),y(m){};

    void solve(){
        LL xx=0,yy=0;
        for(int i=0; i<n; ++i){
            cin >> x[i];
        }
        for(int i=0; i<m; ++i){
            cin >> y[i];
        }
        for(int i=0; i<n-1; ++i){
            xx=(xx+((x[i+1]-x[i])*(i+1)%MOD)*(n-1-i))%MOD;
        }
        for(int i=0; i<m-1; ++i){
            yy=(yy+((y[i+1]-y[i])*(i+1)%MOD)*(m-1-i))%MOD;
        }
        DBG(xx,yy)
        cout << (xx*yy)%MOD <<"\n";

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

