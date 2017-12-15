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
    int n,sum;
    vector<int> a;
    Problem(LL n):n(n),a(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        sum=accumulate(a.begin(),a.end(),0);
        if(sum%10!=0){
            cout << sum<<"\n";
        }else{
            for(int i=0; i<n; ++i){
                if((sum-a[i])%10!=0){
                    cout << sum-a[i] <<endl;
                    break;
                }
                if(i==n-1){
                    cout << 0 <<"\n";
                }
            }
        }
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

