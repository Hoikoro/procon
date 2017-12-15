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
    long long n=0,a,b;
    cin >> n >> a >>b;
    if(n==1){
        cout << (a==b?1:0)<<"\n";
    }else{
        if(a>b){
            cout<< 0 <<"\n";
        }else{
            cout << 1+(n-2)*(b-a)<<"\n";
        }
    }

    return 0;
}

