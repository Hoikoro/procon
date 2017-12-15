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
    vector<vector<int>> p;
    Problem(LL n):n(n),p (n,vector<int>(5)){};

    void solve(){
        for(int i=0; i<n; ++i){
            for(int j=0; j<5; ++j){
                cin >> p[i][j];
            }
        }
        if(n>100){
            cout << 0 <<"\n";
            return;
        }
        vector<int> ans;
        for(int i=0; i<n; ++i){
            bool ok = true;
            for(int j=0; j<n; ++j){
                for(int k=j+1; k<n; ++k){
                    if(j==i or k==i)continue;
                    if(prod(p[i],p[j],p[k])>0)ok=false;
                }
            }
            if(ok)ans.push_back(i);
        }
        cout << ans.size() << "\n";
        for(int i=0; i<(int)ans.size(); ++i){
            cout << ans[i]+1 <<"\n";
        }
    }
    int prod(vector<int> &c, vector<int> &f, vector<int> &s){
        int ret = 0;
        for(int i=0; i<5; ++i){
            ret += (f[i]-c[i])*(s[i]-c[i]);
        }
        return ret;
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

