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
    LL n,a,b;
    vector<LL> h;
    Problem(LL n):n(n),h(n){};
    bool check(LL m){
        LL cnt=0;
        for(int i=0; i<n; ++i){
            cnt+=max((h[i]-b*m+a-b-1)/(a-b),0ll);
        }
        DBG(m,cnt)
        return cnt<=m;
    }
    void solve(){
        cin >> a >> b;
        for(int i=0; i<n; ++i){
            cin >> h[i];
        }
        LL lb=0,ub=2e9;
        while(ub-lb>1){
            LL mid = (lb+ub)/2;
            if(check(mid)) ub=mid;
            else lb=mid;
        }
        cout << ub <<"\n";
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

