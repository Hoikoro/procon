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
double eps=1e-10;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    double c,d;
    vector<pair<double,double>>can;//(a,b)
    cin >> c >> d;
    can.emplace_back(min(c/3*4,d*4),0);
    can.emplace_back(0,min(c/2*7,d/5*7));
    if(c/d<3.0-eps and c/d>0.4-eps){
        can.emplace_back(c*20/13-d*8/13,-c*7/13+d*21/13);
    }
    double ans=0;
    for(auto x : can){
        ans=max(ans,1000.0*x.FI+2000.0*x.SE);
    }
    cout <<fixed << setprecision(10)<< ans <<endl;
    return 0;
}
