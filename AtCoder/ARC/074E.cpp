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
    vector<pair<int,pair<int,int>>> c;
    vector<vector<LL>> dp_;
    vector<LL> sum_;
    Problem(LL n, LL m):n(n),m(m),dp_ (n+1,vector<LL>(n+1)),sum_(n+1){};

    void solve(){
        auto dp = [&](int x, int y) -> auto& {return dp_[x+1][y+1];};
        auto sum = [&](int x) -> auto& {return sum_[x+1];};
        for(int i=0; i<m; ++i){
            int l,r,x;
            cin >> l >> r >> x;
            --l;--r;
            c.push_back({r,{l,x}});
        }
        sort(c.begin(),c.end());

        dp(-1,-1)=3;
        sum(-1)=3;
        int k = 0;
        while(k<(int)c.size() and c[k].first==0){
            if(c[k].second.second>1){
                cout << 0 <<"\n";
                return;
            }
            k++;
        }
        for(int i=1; i<n; ++i){
            for(int j=-1; j<i-1; ++j){
                dp(i-1,j)+=sum(j)+(j==-1?dp(-1,-1):0);
                dp(i-1,j)%=MOD;
                sum(i-1)+=sum(j)+(j==-1?dp(-1,-1):0);
                sum(i-1)%=MOD;
                sum(j)+=sum(j)+(j==-1?dp(-1,-1):0);
                sum(j)%=MOD;
            }
            while(k<(int)c.size() and c[k].first==i){
                for(int j=-1; j<i; ++j){
                    int ub = j==-1?-1:j-1;
                    for(int l=-1; l<=ub; ++l){
                        int cnt = (j>=c[k].second.first)+(l>=c[k].second.first)+1;
                        if(cnt!=c[k].second.second){
                            sum(j)+=MOD-dp(j,l);
                            sum(j)%=MOD;
                            if(j>-1){
                                sum(l)+=MOD-dp(j,l);
                                sum(l)%=MOD;
                            }
                            dp(j,l)=0;
                        }
                    }
                }
                k++;
            }
        }
        LL ans =0;
        for(int i=-1; i<n-1; ++i){
            for(int j=-1; j<n-1; ++j){
                ans += dp(i,j);
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

