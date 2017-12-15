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
    void solve(){
        vector<LL> a(3);
        for(int i=0; i<3; ++i){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        if(a[0]==a[2] && a[0]%2==0){
            cout << -1 <<"\n";
            return;
        }
        LL ans=0;
        while(1){
            if(a[0]%2 || a[1]%2 || a[2]%2){
                cout << ans <<"\n";
                break;
            }
            vector<LL> b(a);
            a[0]=(b[1]+b[2])/2;
            a[1]=(b[0]+b[2])/2;
            a[2]=(b[1]+b[0])/2;
            ++ans;
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    Problem p;
    p.solve();
    return 0;
}

