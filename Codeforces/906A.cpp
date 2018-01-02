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
    int n,ans;
    vector<int> cnt;
    Problem(LL n):n(n),ans(0),cnt(26,1){};

    void solve(){
        bool uni =false;
        for(int i=0; i<n; ++i){
            char c;
            string s;
            cin >> c >> s;
            if(c=='!'){
                vector<int> tmp(26);
                for(int i=0; i<s.size(); ++i){
                    tmp[s[i]-'a']=1;
                }
                for(int i=0; i<26; ++i){
                    cnt[i]&=tmp[i];
                }
                if(uni)ans++;
            }else if(c=='.'){
                for(int i=0; i<s.size(); ++i){
                    cnt[s[i]-'a']=0;
                }
            }else{
                if(uni and i<n-1)ans++;
                cnt[s[0]-'a']=0;
            }
            if(accumulate(cnt.begin(),cnt.end(),0)==1)uni=true;
            DBG(ans,uni,cnt)
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

