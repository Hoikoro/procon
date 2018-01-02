#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#ifdef DEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dreplace(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dreplace(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
template<typename T> using V = vector<T>;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; string s;
    cin >> n>> s;
    V<int> group;
    group.push_back(s[0]-'a');
    for(int i=1; i<s.size(); ++i){
         if(s[i]!=s[i-1])group.push_back(s[i]-'a');
    }
    vector<vector<LL>> dp (n+1,vector<LL>(group.size()+1));
    //dp[0][1]=1;
    VI vis(27,0);

     for(int j=1; j<=group.size(); ++j){
        DBG(group[j-1])
        if(vis[group[j-1]])dp[1][j]=0;
        else dp[1][j]=1;
        vis[group[j-1]]=1;
     }
     for(int i=1; i<n; ++i){
         VLL sum(27,0);
         for(int j=1; j<=group.size(); ++j){
            sum[26]=(sum[26]+dp[i][j])%MOD;
            dp[i+1][j]=((sum[26]-sum[group[j-1]])%MOD+MOD)%MOD;
            sum[group[j-1]]=(sum[group[j-1]]+dp[i+1][j])%MOD;
            DBG(i,j,dp[i+1][j])
         }
     }
     LL ans=0;
     for(int i=1; i<=group.size(); ++i){
         ans=(ans+dp[n][i])%MOD;
     }
     cout << ans <<"\n";


    return 0;
}

