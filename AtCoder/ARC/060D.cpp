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

int f(int a, LL b){
    if(b<a) return b;
    int ret=b%a +f(a,b/a);
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n,s;
    cin >>n >>s;
    LL sqr=sqrt(n);
    if(n==s){
        cout << n+1 <<endl;
        return 0;
    }
    REPN(i,2,sqr){
        //OUT(i)
        if(f(i,n)==s){
            cout << i << endl;
            return 0;
        }
    }

    for(LL i=sqr+1; i>=1;--i){
        LL tmp=s-i;
        //OUT(i)
        if(tmp<0) continue;
        if((n-tmp)%i==0){
            LL base=(n-tmp)/i;
            if(base!=0 && (n/base)+(n%base)==s&&base>i){
            cout << base <<endl;
            return 0;
        }
        }
    }
    cout << -1 <<endl;

    return 0;
}
