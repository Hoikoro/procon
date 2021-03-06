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
    vector<int> cnt;
    Problem(LL n):n(n),cnt(26,INF){};

    void solve(){
        for(int i=0; i<n; ++i){
            vector<int> tmp(26);
            string s;
            cin >> s;
            for(char c : s){
                tmp[c-'a']++;
            }
            for(int i=0; i<26; ++i){
                cnt[i]=min(cnt[i],tmp[i]);
            }
        }
        string ans;
        for(int i=0; i<26; ++i){
            for(int j=0; j<cnt[i]; ++j){
                ans+='a'+i;
            }
        }
        cout << ans <<"\n";
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

