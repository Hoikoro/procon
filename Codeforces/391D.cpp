#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

string dst__; stringstream dss__;
#define DBG(...) dst__=#__VA_ARGS__;replace(dst__.begin(),dst__.end(),',',' ');dss__.str("");dss__.clear(stringstream::goodbit); dss__<<dst__; debug(dss__,__VA_ARGS__);
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s=" "+s;
    int tmp=0,zero[77]={};
    for(int i=1; i<=n; ++i){
        if(s[i]=='0'){
            ++tmp;
            if(tmp>=5)zero[i]=1;
        }else{
            tmp=0;
        }
    }
    vector<VI> dp(n+1,VI((1<<20)));
    vector<VI> dig(n+1,VI(n+1));
    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            int tmp=0;
            for(int k=i; k<j+1; ++k){
                tmp=(tmp<<1)+(s[k]-'0');
            }
            dig[i][j]=tmp;
            if(tmp>20) break;
        }
    }
    dp[0][0]=1;
    for(int i=1; i<n+1; ++i){
        if(dp[i][0]==0) dp[i][0]=1;
        if(zero[i]==1)continue;
        for(int j=i; j>=1; --j){
            //DBG(j,i,dig[j][i])
            if((j<=i-5 && dig[j][i] ==0) || dig[j][i]>20) break;
            if(!dig[j][i])continue;
            for(int k=0; k<(1<<20); ++k){
                dp[i][k|(1<<(dig[j][i]-1))]+=dp[j-1][k];
                //if(k==0){DBG(i,j,k,dig[j][i],(k|(1<<(dig[j][i]-1))),dp[i][k|(1<<(dig[j][i]-1))])}
                if(dp[i][k|(1<<(dig[j][i]-1))]>MOD)dp[i][k|(1<<(dig[j][i]-1))]-=MOD;
            }
            /*for(int k=0; k<(1<<20); ++k){
                if(dp[i][k]>MOD) dp[i][k]-=MOD;
            }*/
        }
    }

    LL ans =0;
    for(int j=1;j<=n;++j){
        for(int i=1; i<=20; ++i){
            ans=(ans+dp[j][(1<<i)-1])%MOD;
        }
    }
    cout << ans <<"\n";
    return 0;
}

