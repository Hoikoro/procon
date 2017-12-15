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
using namespace std;
//emplace_back next_permutation tie get

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define OUT(a) cout<<(a)<<endl;

void egcd(LL &a, LL &b, LL &c, LL &d, LL &e ,LL &f){
    while(b>1){
        //OUT(a)
        LL p=a/b, q=a%b, tmp1=e,tmp2=f;
        e=c-p*e;
        f=d-p*f;
        c=tmp1;
        d=tmp2;
        a=b;
        b=q;
        //cout << a <<b <<c <<d <<e <<f<<endl;
    }
    return;
}

LL solve(LL n, LL m, LL p){
    //OUT(n)OUT(m)OUT(p)
    LL g=__gcd(n,m);
    if(p%g!=0) return 1ll<<40;
    n/=g; m/=g; p/=g;
//cout << n << ' ' << m << ' ' << p << endl;
    LL mm=m,nn=n;
    LL c=1,d=0,e=0,f=1;
    egcd(n,m,c,d,e,f);
    f*=-1;
    e=(((e*p)%mm)+mm)%mm;
    f=(nn*e-p)/mm;
//cout << e << ' ' << f << endl;
    if(f<0)e+=m;
    //OUT(e)
    return e;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n,m,k,s;
    cin >> n >> m >> k;
    LL x[100010]={},y[100010]={},ans[100010];
    REP(i,k){
        cin >> x[i] >> y[i];
        if(n<m) swap(x[i],y[i]);
        //if((x[i]+y[i])%2==0) ans[i]=-1;
    }
    if(n<m) swap(n,m);
    REP(i,k){
        LL tmp=1ll<<55;
        LL tmp2=0;
        tmp2=solve(2*n,2*m,-x[i]+y[i])*2*n+x[i]; //2nx+x[i]=2my+y[i]
        if(tmp2>0) tmp=min(tmp,tmp2);

        tmp2=solve(2*n,2*m,-x[i]+2*m-y[i])*2*n+x[i];//2nx+xi=2my-yi
        if(tmp2>0) tmp=min(tmp,tmp2);

        tmp2=solve(2*n,2*m,x[i]-2*n+y[i])*2*n+2*n-x[i];//2nx-xi=2my+yi
        if(tmp2>0) tmp=min(tmp,tmp2);

        tmp2=solve(2*n,2*m,x[i]-2*n+2*m-y[i])*2*n+2*n-x[i];//2nx-xi=2my-yi
        if(tmp2>0) tmp=min(tmp,tmp2);

        if(tmp>(1ll<<40)) cout << -1 <<endl;
        else cout << tmp <<endl;
    }




    return 0;
}
