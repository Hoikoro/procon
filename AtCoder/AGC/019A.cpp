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
        LL n;
        vector<LL> v(4);
        for(int i=0; i<4; ++i){
            cin >> v[i];
        }
        v[0]*=4;
        v[1]*=2;
        cin >>  n;
        int x=0;
        x=min_element(v.begin(),v.begin()+3)-v.begin();
        if(v[x]*2<v[3]){
            cout << n*v[x] <<"\n";
        }else{
            cout << (n/2)*v[3]+(n%2)*v[x] <<"\n";
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

