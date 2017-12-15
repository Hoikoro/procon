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
    LL n,a,b;
    cin >> n >> a >>b;
    vector<LL> s(n+2);
    for(int i=1; i<=n; ++i){
        cin >> s[i];
    }
    s[0]=-1e18-10;
    s[n+1]=LINF;
    vector<vector<LL>> dp (n+1,vector<LL>(4));
    dp[1][1]=1;dp[1][2]=1;
    queue<pair<LL,LL>> xx,yy;
    xx.push(make_pair(s[0],1ll)),yy.push(make_pair(s[0],1ll));
    for(int i=2; i<=n; ++i){
        LL dif=s[i]-s[i-1];
        DBG(i,dif)
        while(true){
            if(xx.empty())break;
            if(s[i]-xx.front().first<b)break;
            LL q=xx.front().second;
            DBG(1,xx.front().first,q)
            xx.pop();
            dp[i-1][1]=(dp[i-1][1]-q+MOD)%MOD;
            dp[i-1][0]=(dp[i-1][0]+q)%MOD;
        }
        while(true){
            if(yy.empty())break;
            if(s[i]-yy.front().first<a)break;
            LL q=yy.front().second;
            DBG(2,yy.front().first,q)
            yy.pop();
            dp[i-1][2]=(dp[i-1][2]-q+MOD)%MOD;
            dp[i-1][3]=(dp[i-1][3]+q)%MOD;
        }

        DBG(i,dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3])
        if(dif>=a){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
        }else{
            while(!xx.empty())xx.pop();
        }
        if(dif >= b){
            dp[i][3]=dp[i-1][3];
            dp[i][2]=dp[i-1][2];
        }else{
            while(!yy.empty())yy.pop();
        }
        dp[i][1]=(dp[i][1]+dp[i-1][3])%MOD;
        dp[i][2]=(dp[i][2]+dp[i-1][0])%MOD;
        xx.push({s[i-1],dp[i-1][3]});
        yy.push({s[i-1],dp[i-1][0]});

        DBG(i,dp[i][0],dp[i][1],dp[i][2],dp[i][3])
    }
    cout << (dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%MOD <<"\n";


    return 0;
}

