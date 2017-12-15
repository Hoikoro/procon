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
    int n,m;
    vector<int> a,b;
    Problem(LL n,LL m):n(n),m(m),a(n),b(n){};

    void solve(){
        for(int i=0; i<m; ++i){
            int x,y;
            cin >> x >> y;
            x--;y--;
            if(x>y) swap(x,y);
            if(x==0)a[y]=1;
            if(y==n-1)b[x]=1;
        }
        bool ans=false;
        for(int i=1; i<n-1; ++i){
            if(a[i] and b[i])ans=true;
        }
        cout << (ans?"POSSIBLE":"IMPOSSIBLE")<<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,m;
    cin >> n>> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

