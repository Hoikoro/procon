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
    int n;
    cin >> n;
    V<LL> t(n+1);
    t[0]=-INF;
    for(int i=0; i<n; ++i){
        cin >> t[i+1];
    }
    V<LL> dp(n+1,LINF);
    cout << 20 <<"\n";
    dp[0]=0;dp[1]=20;
    for(int i=2; i<=n; ++i){
        dp[i]=min(dp[i],dp[upper_bound(t.begin(),t.end(),t[i]-1440)-t.begin()-1]+120);
        dp[i]=min(dp[i],dp[upper_bound(t.begin(),t.end(),t[i]-90)-t.begin()-1]+50);
        dp[i]=min(dp[i],dp[i-1]+20);
        cout << dp[i]-dp[i-1]<<"\n";
    }



    return 0;
}

