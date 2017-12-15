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


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long a,b,c,n=0;
    cin >> a >> b >> c >> n;
    vector<LL> x(n);
    for(int i=0; i<n; ++i){
        cin >> x[i];
    }
    LL ans =0;
    for(int i=0; i<n; ++i){
        if(b<x[i] and x[i] < c)ans++;
    }
    cout << ans <<"\n";
    return 0;
}

