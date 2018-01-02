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
    int n,k;
    vector<LL> c;
    Problem(LL n, LL k):n(n),k(k),c(k){};
    void solve(){
        for(int i=0; i<k; ++i){
            cin >> c[i];
            c[i]-=n;
            if(c[i]==0){
                cout << 1 <<"\n";
                return;
            }
        }
        DBG(c)
        sort(c.begin(),c.end());
        c.erase(unique(c.begin(),c.end()),c.end());
        if(c[0]>0 or c.back()<0){
            cout << -1 <<"\n";
            return;
        }
        LL br=-c[0]*c.back();
        DBG(br,c)
        vector<LL> dp_(br*2+1,INF);
        auto dp = [&](int x) -> auto& {return dp_[x+br];};
        dp(0)=0;
        for(auto x: c){
            if(x>0){
                for(int i=x; i<=br; ++i){
                    dp(i)=min(dp(i),dp(i-x)+1);
                }
            }else{
                for(int i=x; i>=-br; --i){
                    dp(i)=min(dp(i),dp(i-x)+1);
                }
            }
        }
        LL ans = INF;
        for(int i=1; i<=br; ++i){
            ans=min(ans,dp(i)+dp(-i));
        }
        cout << ans <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,k;
    cin >> n >> k;
    Problem p(n,k);
    p.solve();
    return 0;
}

