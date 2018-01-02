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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    double ans=0.0,c=1.6449340668482264,x;
    cin  >> x;
    REPN(i,1,floor(x)){
        c-=1.0/((double)(i*i));
    }
    double fx=floor(x);
    x-=fx;
    double t[20]={};
    FOR(i,1,5000000){
        double tmp=1.0/((double)i+fx)/((double)i+fx)/((double)i+fx);
        FOR(j,3,20){
            t[j]+=tmp;
            tmp/=((double)i+fx);
        }
    }
    cout << fixed << setprecision(12);
    //FOR(i,3,20) cout << i << ' '<< t[i] << endl;
    ans=c;
    FOR(i,3,20){
        ans+=pow(x,i-2)*(i-1)*t[i]*(i%2?-1.0:1.0);
    }
    cout << ans << endl;
    return 0;
}
