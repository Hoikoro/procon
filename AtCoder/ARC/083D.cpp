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
    vector<vector<LL>> a,wf,ch;
    Problem(LL n):n(n), a (n,vector<LL>(n)),ch (n,vector<LL>(n)){};
    LL solve(){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cin >> a[i][j];
            }
        }
        wf=a;
        for(int k=0; k<n; ++k){
            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    if(wf[i][j]>wf[i][k]+wf[k][j])return -1;
                    else if(wf[i][j] == wf[i][k]+wf[k][j] and k!=i and k!= j)ch[i][j]=1;
                }
            }
        }
        LL ans =0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(ch[i][j]==0)ans+=a[i][j];
            }
        }
        return ans/2;

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin >> n;
    Problem p(n);
    cout << p.solve() << "\n";
    return 0;
}

