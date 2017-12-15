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
    vector<string> names;
    vector<int> ans;
    Problem(LL n):n(n),names(n),ans(n){};

    void solve(){
        cin >> k;
        for(int i=0; i<n; ++i){
            if(i<26)names[i]='A'+i;
            else{
                names[i]='A'+(i%26);
                names[i]+='x';
            }
        }
        vector<string> yn(n);
        for(int i=k-1; i<n; ++i){
            cin >> yn[i];
        }
        if(yn[k-1]=="YES"){
            for(int i=0; i<k; ++i){
                ans[i]=i;
            }
        }else{
            ans[0]=1;
            for(int i=1; i<k; ++i){
                ans[i]=i;
            }
        }
        for(int i=k; i<n;){
            if(yn[i]=="YES"){
                ans[i]=i;
                ++i;
            }else{
                int s=1;
                while(i+s<n and yn[i+s]=="NO"){
                    if(s==k-1)break;
                    s++;
                }
                ans[i]=ans[i-k+s];
                DBG(i,s,i-k+s)
                for(int j=1; j<s; ++j){
                    ans[i+j]=i+j;
                }
                i+=s;
            }
        }
        for(int i=0; i<n; ++i){
            cout << names[ans[i]];
            if(i<n-1)cout << ' ';
        }
        cout << "\n";
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

