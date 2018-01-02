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
    string a,b;
    deque<char> t;
    deque<char> s;
    void solve(){
        cin >> a >> b;
        int n= a.length();
        vector<char> ans(n);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<char>());

        for(int i=0; i<(n+1)/2; ++i){
            s.push_back(a[i]);
        }
        for(int i=0; i<n/2; ++i){
            t.push_back(b[i]);
        }

        int f=0,g=n-1;
        for(int i=0; i<n; ++i){
            DBG(i,ans)
            if(i%2==0){
                if(s.front()<t.front()){
                    ans[f++]=s.front();
                    s.pop_front();
                }else{
                    ans[g--]=s.back();
                    s.pop_back();
                }
            }else{
                if(s.front()<t.front()){
                    ans[f++]=t.front();
                    t.pop_front();
                }else{
                    ans[g--]=t.back();
                    t.pop_back();
                }
            }
        }
        for(int i=0; i<n; ++i){
            cout << ans[i];
        }
        cout <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    Problem p;
    p.solve();
    return 0;
}

