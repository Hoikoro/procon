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

typedef long long LL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n)-1)
#define FOR(i,a,b) for(int (i)=(a); (i)<=(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

#define MOD 1000003
long long modpow(long long a, long long n){
    if(n==0) return 1;
    long long re=modpow((a*a)%MOD,n/2)%MOD;
    if(n%2==1) re= (re*a)%MOD;
    return re;
}
long long pow_(long long a, long long n){
    if(n==0) return 1;
    long long re=pow_(a*a,n/2);
    if(n%2==1) re= re*a;
    return re;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,k;
    cin >> n >> k;
    if(n<=62&&pow_(2,n)<=k-1){
        cout << 1 << ' ' <<1 <<endl;
        return 0;
    }
    LL d=0,tmp=k-1;
    while(tmp>0){
        tmp/=2;
        d+=tmp;
    }
    LL den=modpow(modpow(2,n),k-1)*modpow(modpow(2,d),MOD-2)%MOD;

    LL num=1;
    LL pown=modpow(2,n);
    REPN(i,1,k-1){
        num=num*(pown-i)%MOD;
        if(num==0) break;
    }
    num=num*modpow(modpow(2,d),MOD-2)%MOD;
    //cout << num << ' ' <<den << endl;

    num=(den-num+MOD)%MOD;
    cout << num << ' ' <<den << endl;

    //OUT((3*modpow(2,49)-1)%MOD)
    return 0;
}
