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
    vector<vector<pair<int,int>>> dp;
    vector<int> s;
    Problem(LL n):n(n),dp (27,vector<pair<int,int>>(100001,{0,-1})),s(400){};

    void solve(){
        for(int i=1; i<400; ++i){
            s[i]=i*(i-1)/2;
        }
        dp[0][0]={0,0};
        for(int i=0;i<=25; ++i){
            for(int j=0; j<100001; ++j){
                if(dp[i][j].second==-1)continue;
                for(int k=1; k<330; ++k){
                    if(j+s[k]<100001){
                        dp[i+1][j+s[k]]={i,k};
                    }else break;
                }
            }
            bool fin = true;
            for(int j=0; j<100001; ++j){
                if(dp[i+1][j].second==-1)fin =false;
            }
            if(fin){
                DBG(i)
                break;
            }
        }
        DBG(dp[2][11])
        vector<int> ans(3);
        for(int i=3; i>=1; --i){
            auto tmp = dp[i][n];
            DBG(i,n,tmp)
            ans[tmp.first]= tmp.second;
            n-=s[tmp.second];
        }
        DBG(ans)
        for(int i=0; i<3; ++i){
            for(int j=0; j<ans[i]; ++j){
                cout << (char)('a'+i);
            }
        }
        cout <<"\n";
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

