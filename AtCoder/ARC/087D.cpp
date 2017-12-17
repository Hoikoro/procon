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
    int x,y;
    string s;
    bool check(int t, vector<int> &v,int xx =0){
        DBG(t)
        if(v.size()==0 and t==0) return true;
        int sum = accumulate(v.begin(),v.end(),0);
        if(abs(t)>sum)return false;
        vector<vector<int>> dp ((int)v.size()+1,vector<int>(sum+1));
        dp[0][0]=1;
        for(int i=0; i<(int)v.size(); ++i){
            /*if(xx==1 and i ==0){
                dp[1][v[0]]=1;
                continue;
            }*/
            for(int j=0; j<=sum-v[i]; ++j){
                dp[i+1][abs(j+v[i])]|=dp[i][j];
                dp[i+1][abs(j-v[i])]|=dp[i][j];
            }
        }
        DBG(dp)
        return dp[(int)v.size()][abs(t)]>0;
    }
    void solve(){
        cin >> s >> x >> y;
        vector<vector<int >> l(2);
        s+='T';
        for(int i=0,cnt =0,j=0; i<(int)s.size(); ++i){
            if(s[i] == 'F'){
                cnt ++;
            }else{
                l[j%2].push_back(cnt);
                cnt =0;
                j++;
            }
        }
        x-=l[0][0];
        l[0].erase(l[0].begin());
        DBG(l)
        if(check(x,l[0],1) && check(y,l[1]))cout << "Yes"<<"\n";
        else cout << "No" <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Problem p;
    p.solve();
    return 0;
}

