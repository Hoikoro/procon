#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

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

struct Problem{
    string s;
    int l;
    vector<vector<vector<Modint>>> dp;
    Problem(string s):s(s),l((int)s.size()),dp (10,vector<vector<Modint>>(l,vector<Modint>(l))){};

    void solve(){
        for(int i=1; i<10; ++i){
            dp[i][0][0]=1;
            dp[i][1][0]=i;
            dp[i][1][1]=10-i;
            for(int j=2; j<l; ++j){
                for(int k=0; k<=j; ++k){
                    dp[i][j][k]=dp[i][j-1][k]*i;
                    if(k>0)dp[i][j][k]+=dp[i][j-1][k-1]*(10-i);
                }
            }
        }
        Modint ans =0;
        vector<Modint> one(l+1);
        for(int i=1; i<(int)one.size(); ++i){
            one[i]=one[i-1]*10+1;
        }
        vector<int> cnt (10);
        for(int i=0; i<l; ++i){
            int len = l-1-i;
            for(int j=0; j<s[i]-'0'; ++j){
                vector<int> cnt2(cnt);
                for(int k=j; k>=0; --k){
                    cnt2[k]++;
                }
                for(int k=1; k<10; ++k){
                    for(int h=0; h<=len; ++h){
                        ans += one[h+cnt2[k]]*dp[k][len][h];
                    }
                }
            }
            for(int j=s[i]-'0'; j>=0; --j){
                cnt[j]++;
            }
        }
        sort(s.begin(),s.end());
        Modint c=1;
        for(int i=l-1; i>=0; --i,c*=10){
            ans+=c*(s[i]-'0');
        }
        cout << ans <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    Problem p(s);
    p.solve();
    return 0;
}

