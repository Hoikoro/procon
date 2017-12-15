#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#define DBG(...) {string dst__=#__VA_ARGS__;dreplace(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dreplace(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=924844033;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

long long modpow(long long a, long long n){
    if(n==0) return 1;
    long long re=modpow((a*a)%MOD,n/2)%MOD;
    if(n%2==1) re= (re*a)%MOD;
    return re;
}
struct Modint{
    public:
    long long Mod = MOD;
    long long v;
    template<typename T> Modint(T x){
        x %= Mod;
        long long y = (long long)x;
        if(y<0) y+=Mod;
        v=y;
    }
    Modint():v(0){}
    Modint &operator+=(Modint a){
        v=(v+a.v);
        if(v>Mod) v-=Mod;
        return *this;
    }
    Modint &operator-=(Modint a){
        v=(v-a.v);
        if(v<0)v+=Mod;
        return *this;
    }
    Modint &operator*=(Modint a){
        v=(v*a.v)%Mod;
        return *this;
    }
    Modint &operator/=(Modint a){
        v=(v*modpow(a.v,Mod-2))%Mod;
        return *this;
    }
    Modint operator+(Modint a){
        long long t= (v)+(a.v);
        return Modint(t);
    }
    Modint operator-(Modint a){
        long long t= (v)-(a.v);
        return Modint(t);
    }
    Modint operator*(Modint a){
        long long t= (v)*(a.v);
        return Modint(t);
    }
    Modint operator/(Modint a){
        long long t=(v)*modpow(a.v,Mod-2);
        return Modint(t);
    }
};
ostream& operator<< (ostream& os, const Modint m) {
    return os << m.v;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,k;
    cin >> n >>k;
    vector<int> path;
    for(int i=1; i<=k; ++i){
        for(int j=0; j<2; ++j){
            int next_index;
            if(path.empty())next_index=0;
            else next_index=path.back()+1;
            for(int l=0; l<(n-i)/k; ++l){
                path.push_back(next_index);
            }
        }
    }
    vector<vector<Modint>>  dp(path.size(),vector<Modint>(n+1)),dp2(path.size(),vector<Modint>(n+1));

    dp2[0][1]=1;
    dp[0][0]=1;
    dp[1][0]=1;dp[1][1]=1;dp2[1][1]=1;
    dp2[1][2]=(path[0]==path[1]?0:1);
    for(int i=2; i<path.size(); ++i){
        dp[i][0]=1;
        for(int j=1; j<=n;++j){
            if(path[i]!=path[i-1]){
                dp2[i][j]=dp[i-1][j-1]+dp2[i-1][j-1];
                dp[i][j]=dp[i-1][j]+dp2[i-1][j];
            }
            else{
                dp2[i][j]=dp[i-1][j-1];
                dp[i][j]=dp[i-1][j]+dp2[i-1][j];
            }
        }
    }

    Modint ans=1;
    vector<Modint> fac(2001,1);
    for(int i=1; i<=n; ++i){
        ans*=i;
        fac[i]=ans;
    }
    for(int i=1; i<=n; ++i){
        if(i%2)ans-=(dp.back()[i]+dp2.back()[i])*fac[n-i];
        else ans+=(dp.back()[i]+dp2.back()[i])*fac[n-i];
    }

    cout << ans <<"\n";
    return 0;
}
