#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
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
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a (2002,vector<int>(2002));
    auto dp = [&](int x, int y) -> int& {return (x<0||y<0)?a[0][0]:a[x+1][y+1];};
    dp(0,0)=1;
    for(int i=0; i<=m+n; i=i+k-1){
        int l=max(0,i-m), h=min(i,m);
        for(int j=0; j<k; ++j){
            dp(l,h)+=dp(l-k+1+j,h-j);
            if(dp(l,h)>MOD)dp(l,h)-=MOD;
        }
        for(int j=max(0,i-m)+1; j<=min(i,n); ++j){
            dp(j,i-j)=dp(j-1,i-j+1)+dp(j,i-j-k+1)-dp(j-k,i-j+1);
            if(dp(j,i-j)<0)dp(j,i-j)+=MOD;
            else if(dp(j,i-j)>MOD)dp(j,i-j)-=MOD;
        }
    }
    int ans=0;
    for(int i=n; i>0; i-=k-1){
        for(int j=m; j>0; j-=k-1){
            for(int h=1; h<k; ++h){
                ans+=dp(i-h,j-k+h);
                if(ans>MOD)ans-=MOD;
            }
        }
    }
    cout << ans <<"\n";
    return 0;
}

