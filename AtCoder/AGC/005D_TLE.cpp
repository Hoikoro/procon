#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

#define MOD 924844033
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
    Modint &operator+=(Modint &a){
        v=(v+a.v)%Mod;
        return *this;
    }
    Modint &operator-=(Modint &a){
        v=(v-a.v)%Mod;
        return *this;
    }
    Modint &operator*=(Modint &a){
        v=(v*a.v)%Mod;
        return *this;
    }
    Modint &operator/=(Modint &a){
        v=(v*modpow(a.v,Mod-2))%Mod;
        return *this;
    }
    Modint operator+(Modint &a){
        long long t= (v)+(a.v);
        return Modint(t);
    }
    Modint operator-(Modint &a){
        long long t= (v)-(a.v);
        return Modint(t);
    }
    Modint operator*(Modint &a){
        long long t= (v)*(a.v);
        return Modint(t);
    }
    Modint operator/(Modint &a){
        long long t=(v)*modpow(a.v,Mod-2);
        return Modint(t);
    }
};
ostream& operator<< (ostream& os, const Modint m) {
    return os << m.v;
}

void calc(vector<vector<Modint>> &a){
    REPN(i,1,a.size()+1){
        FOR(j,0,i+1){
            //dp[i][j]=
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,k;
    cin >> n >>k;
    vector<int> a(n);
    iota(a.begin(),a.end(),1);
    int cnt=0,cnt2=0;
    vector<vector<Modint>> dp((n-k)*2,vector<Modint>(n)); //dp[current][used]
    Modint  fac[2002];
    fac[0]=fac[1]=1;
    FOR(i,2,2001){
        Modint j(i);
        fac[i]=fac[i-1]+j;
    }
    calc(dp);


    do{
        bool frag=true;
        REP(i,n){
            if(abs(i+1-a[i])==k) frag=false;
        }
        cnt2++;
        if(frag){
            cnt++;
            REP(i,n){
                cout<< a[i] <<' ';
            }
            cout << ' ' << cnt << endl;

        }
    }while(next_permutation(a.begin(),a.end()));
    cout << cnt << endl;


    return 0;
}
