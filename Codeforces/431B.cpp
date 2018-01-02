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
    int n,w,h;
    vector<vector<tuple<int,int,int>>> pr,po;
    vector<pair<int,int>> ans;
    Problem(LL n):n(n),pr(200001),po(200001),ans(n){};

    void solve(){
        cin >> w >> h;
        for(int i=0; i<n; ++i){
            int a,b,c;
            cin >> a >> b >> c;
            if(a == 1){
                pr[100000-b+c].push_back({b,0,i});
                po[100000-b+c].push_back({b,h,i});
            }else{
                pr[100000-b+c].push_back({0,-b,i});
                po[100000-b+c].push_back({w,-b,i});
            }
        }
        for(int i=0; i<(int)pr.size(); ++i){
            sort(pr[i].begin(),pr[i].end());
            sort(po[i].begin(),po[i].end());
        }
        for(int i=0; i<(int)pr.size(); ++i){
            if(pr[i].size()>0)DBG(i)
            for(int j=0; j<(int)pr[i].size(); ++j){
                DBG(pr[i][j],po[i][j])
                ans[get<2>(pr[i][j])]={get<0>(po[i][j]),get<1>(po[i][j])};
            }
        }
        DBG(ans)
        for(int i=0; i<n; ++i){
            cout << abs(ans[i].first) <<' '<<abs(ans[i].second) <<endl;
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

