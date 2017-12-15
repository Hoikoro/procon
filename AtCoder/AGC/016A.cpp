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
    string s;
    void solve(){
        cin >> s;
        vector<vector<int>> a (26);
        for(int i=0; i<26; ++i){
            a[i].push_back(0);
        }
        for(int i=0; i<(int)s.size(); ++i){
            a[s[i]-'a'].push_back(i+1);
        }
        for(int i=0; i<26; ++i){
            a[i].push_back((int)s.size()+1);
        }
        int ans=INF;
        for(int i=0; i<26; ++i){
            int tmp=0;
            for(int j=0; j<a[i].size()-1; ++j){
                tmp=max(tmp,a[i][j+1]-a[i][j]-1);
            }
            ans=min(ans,tmp);
        }
        cout<<ans<<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Problem p;
    p.solve();
    return 0;
}

