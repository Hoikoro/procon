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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL ans=(1ll<<62)-1;
    vector< LL > a(3);
    REP(i,3){
        cin >> a[i];
    }
    REP(i,3){
        //cout << ans << endl;
        LL t=abs(a[i%3]*a[(i+1)%3]*(a[(i+2)%3]/2)-a[i%3]*a[(i+1)%3]*(a[(i+2)%3]-a[(i+2)%3]/2));
        ans=min(ans,t);
    }
    cout << ans << endl;


    return 0;
}
