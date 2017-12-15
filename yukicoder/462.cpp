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
    int n,k;
    cin >> n >> k;
    vector<LL> a;
    LL ans=1ll;
    a.push_back(0ll);
    a.push_back((1ll<<n)-1ll);
    REP(i,k){
        LL tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(ALL(a));
    a.erase(unique(ALL(a)),a.end());
    FOR(i,1,a.size()){
        LL cnt=__builtin_popcountll(a[i])-__builtin_popcountll(a[i-1]);
        REP(j,n){
            if(((a[i-1]>>j)&1)>((a[i]>>j)&1)){
                cout << 0 << endl;
                return 0;
            }
        }
        for(long long k=1;k<cnt+1;++k){
            ans=(ans*k)%MOD;
        }
    }
    cout << ans <<endl;
    return 0;
}
