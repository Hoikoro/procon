#include <bits/stdc++.h>

using LL = long long;
constexpr LL  MOD=1E9+7;

namespace Problem{
using namespace std;

template<long long Mod=MOD>
struct Modint{
    public:
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
        if(v>=Mod) v-=Mod;
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
        v=(v*a.mpow(Mod-2).v)%Mod;
        return *this;
    }
    Modint mpow(Modint n){return mpow(n.v);}
    Modint mpow(long long n){
        long long i=1,p=v;
        Modint ret(1);
        while(i<=n){
            if(i&n) ret*=p;
            i=(i<<1);
            p=(p*p)%Mod;
        }
        return ret;
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
        return a.mpow(Mod-2)**this;
    }
};
template<long long M>
ostream& operator<< (ostream& os, const Modint<M> m) {
    return os << m.v;
}
struct Factorial{
    int n;
    vector<long long> fac,inv;
    Factorial(long long n):n(n),fac(n+1),inv(n+1){
        fac[0]=1;
        for(int i=0; i<n; ++i)fac[i+1]=fac[i]*(i+1)%MOD;
        inv[n]=modpow(fac[n],MOD-2);
        for(int i=n-1; i>=0; --i)inv[i]=inv[i+1]*(i+1)%MOD;
    };
    long long modpow(long long a, long long n,long long mod=MOD){
        long long i=1,ret=1,p=a;
        while(i<=n){if(i&n){ret=(ret*p)%mod;}i=(i<<1);p=(p*p)%mod;}
        return ret;
    }
    long long comb(int a, int b){return (fac[a]*inv[b]%MOD)*inv[a-b]%MOD;}
};
class Solver{
public:
    Modint<> n,k;
    vector<Modint<>> dp;
    Factorial fac;
    Solver(Modint<> n, Modint<> k):n(n),k(k),dp(k.v+1),fac(11111){};

    void solve(){
        dp[1] = Modint<>(2).mpow(n.v-1)*n.v;
        for(int i=2; i<=k.v; ++i){
            dp[i] = dp[i-1]*n;
            for(int d=1; d<=i-1; ++d){
                if((i-d)%2 == 0) dp[i]-=dp[d]*fac.comb(i-1,d-1);
                else dp[i]+=dp[d]*fac.comb(i-1,d-1);
            }
            dp[i]/=2;
        }
        cout << dp[k.v].v <<"\n";
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0,k;
    std::cin >> n >> k;
    Problem::Solver sol(n,k);
    sol.solve();
    return 0;
}

