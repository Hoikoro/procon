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
    int n;
    vector<int> a;
    Problem(LL n):n(n),a(1){};

    void solve(){
        cin >> a[0];
        for(int i=1; i<n; ++i){
            int tmp;
            cin >> tmp;
            if(tmp!=a.back())a.push_back(tmp);
        }
        if(a.size()==1){cout << 1 <<"\n";return;}
        int ans=1,dir=a[1]>a[0]?1:-1;
        for(int i=2; i<a.size(); ++i){
            if(dir==0){
                dir=a[i]>a[i-1]?1:-1;
            }else if((a[i]-a[i-1])*dir<0){
                ++ans;
                dir=0;
            }
        }
        cout << ans <<"\n";

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin  >> n;
    Problem p(n);
    p.solve();
    return 0;
}

