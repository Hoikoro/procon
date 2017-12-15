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

//make_tuple emplace_back next_permutation
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define ALL(v) (v).begin(),(v).end()
#define SI(v) (int)(v).size()

string dst__; stringstream dss__;
#define DBG(...) dst__=#__VA_ARGS__;replace(ALL(dst__),',',' '); dss__<<dst__; debug(dss__,__VA_ARGS__);
inline void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<' '<<f<<' '; debug(ds,r...);}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=(1ll<<21);

vector<pair<LL,LL>> fac;
VLL ord;
long long pow_(long long a, long long n){
    if(n==0) return 1;
    long long re=pow_(a*a,n/2);
    if(n%2==1) re= re*a;
    return re;
}
long long modpow(long long a, long long n){
    if(n==0) return 1;
    long long re=modpow((a*a)%MOD,n/2)%MOD;
    if(n%2==1) re= (re*a)%MOD;
    return re;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >>n;
    fac.push_back(make_pair(0ll,1ll));
    ord.push_back(0ll);
    FOR(i,1,(1ll<<21)+1){
        if(i%2==1) ord.push_back(0);
        else ord.push_back(ord[i/2]+1);
        fac.emplace_back(fac[i-1].FI+ord[i],fac[i-1].SE*(i/(1ll<<ord[i]))%MOD);
    }


    REP(i,n){
        LL a,b,c;
        cin >> a >>b >> c;
        if(c%2==0){
            cout << 0 << endl;
            continue;
        }
        //c:odd
        //comb=c*((b+c-1)C(b))
        PLL num,den,comb;
        den=fac[b];
        num=make_pair(fac[b+c-1].FI-fac[c-1].FI,fac[b+c-1].SE*modpow(fac[c-1].SE,(1ll<<20)-1)%MOD);
        comb=make_pair(num.FI-den.FI,(num.SE*modpow(den.SE,(1ll<<20)-1)%MOD*c)%MOD);
        //x=(a+comb-1)C(a)
        LL ord_num,ord_den,tmp1,tmp2;
        ord_den=fac[a].FI;
        tmp1=((comb.SE<<comb.FI)-1)%MOD;
        tmp2=(tmp1+a)%MOD;
        if(tmp2<tmp1){
            cout << 0 <<endl;
            continue;
        }
        ord_num=fac[tmp2].FI-fac[tmp1].FI;
        if(ord_num>ord_den)cout << 0<<endl;
        else cout << 1 <<endl;
    }


    return 0;
}
