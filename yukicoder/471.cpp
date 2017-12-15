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
#define debug(a) cerr<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m;
    cin >> m;
    VI x(m+2),y(m+2);
    REP(i,m){
        cin >> x[i] >> y[i];
    }
    cout<< "? 0 0" <<endl;
    fflush(stdout);
    cin >> x[m] >>y[m];
    cout<< "? 0 1" <<endl;
    fflush(stdout);
    cin >> x[m+1] >>y[m+1];
    vector<int> ans(4);
    if(x[m+1]-x[m]==0 and y[m+1]-y[m]==1) ans={1,0,0,1};
    if(x[m+1]-x[m]==1 and y[m+1]-y[m]==0) ans={0,1,-1,0};
    if(x[m+1]-x[m]==0 and y[m+1]-y[m]==-1) ans={-1,0,0,-1};
    if(x[m+1]-x[m]==-1 and y[m+1]-y[m]==0) ans={0,-1,1,0};

    cout<<'!'<<endl;
    REP(i,m){
        fflush(stdout);
        cout << x[m]+ans[0]*x[i]+ans[1]*y[i] <<' '<< y[m]+ans[2]*x[i]+ans[3]*y[i] <<endl;
    }

    return 0;
}
