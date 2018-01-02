#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

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

struct Factorial{
    int n;
    vector<long long> fac,inv,bell;
    Factorial(long long n):n(n),fac(n+1),inv(n+1),bell(0,1){
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
    void calc_bell(int a, int b){
        assert(a<=b);
        bell.resize(b);
        bell[0]=1;
        for(int i=a; i<b; ++i){
            for(int j=0; j<i; ++j){
                bell[i]+=bell[j]*comb(i-1,j);
                bell[i]%=MOD;
            }
        }
    }
    long long get_bell(int i){
        if((int)bell.size()<=i)calc_bell((int)bell.size(),i+1);
        return bell[i];
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;

    Factorial p(n);
    return 0;
}

