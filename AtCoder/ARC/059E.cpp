#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL; typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;
#define MOD 1000000007



long long modpow(long long a, long long n){
    if(n==0) return 1;
    long long re=modpow((a*a)%MOD,n/2)%MOD;
    if(n%2==1) re= (re*a)%MOD;
    return re;
}
class Modint{
    public:
    long long Mod = MOD;
    long long v;
    Modint():v(0){}
    template<typename T> Modint(T x){
        x %= Mod;
        long long y = (long long)x;
        if(y<0) y+=Mod;
        v=y;
    }
    Modint &operator+=(Modint a){
        v=(v+a.v)%Mod;
        return *this;
    }
    Modint &operator-=(Modint a){
        v=(v-a.v)%Mod;
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
Modint dp[404][404],po[404][404];
long long n,c,a[404],b[404];

void solve(int n, int c){
    REPN(i,1,n){
        REPN(j,0,c+1){
            FOR(k,0,j+1){
                dp[i][j]+=dp[i-1][j-k]*(po[b[i]][k]-po[a[i]-1][k]);

            }
            //OUT(dp[i][j])
        }
    }

}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> c;
    dp[0][0]=1;

    REP(i,n){
        cin >> a[i+1];
    }
    REP(i,n){
        cin >> b[i+1];
    }
    REPN(i,1,401){
        REPN(j,0,401){
            po[i][j]=po[i-1][j]+modpow(i,j);
            //OUT(po[i][j])
        }
    }
    solve(n,c);
    cout << dp[n][c] <<endl;



    return 0;
}
