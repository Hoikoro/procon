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
    Problem(LL n):n(n){};
    int digsum(int a){
        int ret=0;
        while(a>0){
            ret+=a%10;
            a/=10;
        }
        return ret;
    }
    void solve(){
        vector<int> ans;
        for(int i=max(0,n-81); i<=n; ++i){
            if(digsum(i)+i==n)ans.push_back(i);
        }
        cout << (int)ans.size() <<"\n";
        for(int i=0; i<(int)ans.size(); ++i){
            cout << ans[i] <<((i!=(int)ans.size()-1)?" ":"\n");
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

