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
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
#include <random>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define dump(a) cerr<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

long long modpow(long long a, long long n){
    if(n==0) return 1;
    long long re=modpow((a*a)%MOD,n/2)%MOD;
    if(n%2==1) re= (re*a)%MOD;
    return re;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    LL l=s.size();
    LL p[3]={999999937,MOD};
    LL b[3]={149853437,2345752};
    vector<VLL> rh(l+2,VLL(3)), revh(l+2,VLL(3));
    vector<VLL> power(l+2,VLL(3));
    REP(i,3) power[0][i]=1;
    FOR(i,1,l+1){
        REP(j,2){
            rh[i][j]=(rh[i-1][j]*b[j]+(s[i-1]-' '))%p[j];
            revh[i][j]=(revh[i-1][j]*b[j]+(s[l-i]-' '))%p[j];
            power[i][j]=power[i-1][j]*b[j]%p[j];
        }
    }

    auto ok=[&](int a,int b){
        REP(i,2){
            if((rh[b][i]-(rh[a-1][i]*power[b-a+1][i]%p[i])+p[i])%p[i]!=(revh[l-a+1][i]-(revh[l-b][i]*power[b-a+1][i]%p[i])+p[i])%p[i]) return false;
        }
        return true;
    };

    VLL p3(l+2);
    for(int i=l;i>=4;--i){
        if(ok(i,l)){
            p3[i]=p3[i+1]+1;
        }else{
            p3[i]=p3[i+1];
        }
    }
    LL ans=0;
    FOR(i,1,l-2){
        if(ok(1,i)){
            FOR(j,i+1,l-1){
                if(ok(i+1,j)){
                    ans=ans+p3[j+2];
                }
            }
        }
    }

    cout<< ans <<endl;

    return 0;
}
