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
#include <numeric>
using namespace std;

typedef long long LL; typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

LL n,k,a[110000],b[110000],low[110000],hi[110000],ans;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>k;
    REP(i,n){
        cin >> a[i];
    }
    REP(i,n){
        cin >> b[i];
    }

    REP(i,n){
        low[i]=b[i]/a[i];
        hi[i]=(k+b[i])/a[i];
    }

    LL  lower = 0,upper = 2000200000;
    for(int i=0;i<200;i++){
    LL m = (lower+upper) / 2;
    bool pos=true; LL kk=k;
    REP(i,n){
        if(low[i]<m){
            kk=kk-(m*a[i]-b[i]);
        }
        if(kk<0){
            pos=false;
            break;
        }
    }
    if(!pos){
        upper = m;
    }else{
        lower = m;
    }
    ans=m;
    }

    cout << ans << endl;
    return 0;
}
