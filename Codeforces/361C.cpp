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

LL calc(LL a){
    LL re=0,tmp;
    for(LL i=2;i<200001;i++){
        tmp=a/(i*i*i);
        if(tmp==0) break;
        re+=tmp;
    }
    return re;
}
LL n,ans;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //OUT(calc(1000000000000000-1))
    cin >>n;
    LL lower = 0,upper = 8E16;
    for(LL i=0;i<100;i++){
    LL m = (lower+upper) / 2;
    if(calc(m)>n || (calc(m)==n && calc(m-1)==n )){
        upper = m;
    }else{
        lower = m;
    }
    ans=m;
    }
    if(calc(ans)==n) cout << ans << endl;
    else cout << "-1" <<endl;
    return 0;
}
