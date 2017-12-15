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
    int n;cin >> n;
    vector<LL> a(n+1),b(n);
    REP(i,n) cin >> b[i];
    a[0]=1;
    LL ma[2]={-LINF,-LINF},mi[2]={LINF,LINF},dif=0;
    FOR(i,1,n+1){
        if(i%2)a[i]=b[i-1]-a[i-1];
        else a[i]=a[i-1]-b[i-1];
        int d=((i+3)/2)%2;
        ma[d]=max(ma[d],a[i]);
        mi[d]=min(mi[d],a[i]);
        if(ma[1]>1e18 or mi[0]<1){
            cout <<-1 <<endl;
            return 0;
        }
    }
    dif=max(max(0ll,-mi[1]+1),max(0ll,ma[0]-(LL)1e18));
    mi[0]-=dif;
    ma[1]+=dif;
    if(mi[0]<1 or ma[1]>1e18) {
        cout << -1 << endl;
    }else{
        cout << n+1<<endl;
        REP(i,n+1){
            cout << a[i]+(((i+3)/2)%2 ? dif : -dif) <<endl;
        }
    }


    return 0;
}
