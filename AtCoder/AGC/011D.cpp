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
    string s;
    Problem(LL n):n(n){};
    void out(int pos){
        vector<char> ab;
        for(int i=0; i<pos; ++i){
            if(i%2==0) ab.push_back('A');
            else ab.push_back('B');
        }
        reverse(ab.begin(),ab.end());
        for(int i=pos; i<n; ++i){
            if(pos%2==0)cout << s[i];
            else if(s[i]=='A')cout << 'B';
            else cout << 'A';
        }
        for(auto c : ab){
            cout << c;
        }
        cout << "\n";
    }
    void ba(int l){
        for(int i=0; i<l; ++i){
            if(i%2==0) cout << 'B';
            else cout << 'A';
        }
        cout << "\n";
    }
    void solve(){
        cin >> k >> s;
        int cnt=0;
        for(int i=0; i<n; ++i){
            if(cnt==k){out(i);return;}
            if((s[i]=='A' and i%2==0)or(s[i]=='B' and i%2==1)){
                if(s[i]=='A')s[i]='B';
                else s[i]='A';
                ++cnt;
                if(cnt==k){out(i);return;}
            }
            ++cnt;
        }
        if(n%2==0){
            ba(n);
        }else{
            if((k-cnt)%2==0)cout <<'A';
            else cout << 'B';
            ba(n-1);
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

