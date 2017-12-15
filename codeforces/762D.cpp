#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dbgsplit(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dbgsplit(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}
using LL = long long;
constexpr long long LINF=334ll<<53; constexpr int INF=15<<26; constexpr long long MOD=1E9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<LL>> a (n+1,vector<LL>(3));
    vector<vector<LL>> dp (n+1,vector<LL>(3,-LINF));
    for(int i=0; i<3; ++i){
        for(int j=0; j<n; ++j){
            cin >> a[j+1][i];
        }
    }
    dp[0][0]=0;
    for(int i=1; i<=n; ++i){
        dp[i][0]=max({dp[i-1][0]+a[i][0],dp[i-1][1]+a[i][0]+a[i][1],dp[i-1][2]+a[i][0]+a[i][1]+a[i][2]});
        dp[i][1]=max({dp[i-1][0]+a[i][0]+a[i][1],dp[i-1][1]+a[i][1],dp[i-1][2]+a[i][1]+a[i][2]});
        dp[i][2]=max({dp[i][2],dp[i-1][0]+a[i][0]+a[i][1]+a[i][2],dp[i-1][1]+a[i][1]+a[i][2],dp[i-1][2]+a[i][2]});
        if(i>=2){
            LL sum=a[i][0]+a[i][1]+a[i][2]+a[i-1][0]+a[i-1][1]+a[i-1][2];
            dp[i][0]=max({dp[i][0],dp[i-2][0]+sum,dp[i-2][2]+sum});
            dp[i][2]=max({dp[i][2],dp[i-2][0]+sum,dp[i-2][2]+sum});
        }
    }
    cout << dp[n][2] <<"\n";


    return 0;
}

