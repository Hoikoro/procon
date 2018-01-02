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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,n,x,y,v;
    double ans=10000000.0;
    cin >> a >> b >>n;


    REP(i,n){
        cin >> x >> y >> v;
        double time=sqrt(((double)x-a)*(x-a)+((double)y-b)*(y-b))/(double)v;
        ans=min(time,ans);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
