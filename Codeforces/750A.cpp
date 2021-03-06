#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

//make_tuple emplace_back next_permutation push_back make_pair second first
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define ALL(v) (v).begin(),(v).end()
#define SI(v) (int)(v).size()
#define endl "\n"

string dst__; stringstream dss__;
#define DBG(...) dst__=#__VA_ARGS__;replace(ALL(dst__),',',' '); dss__<<dst__; debug(dss__,__VA_ARGS__);
inline void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,t=0,ans=0;
    cin >> n >> k;
    for(int i=1; i<n+1; ++i){
        if(t+5*i>240-k) break;
        t+=5*i;
        ans++;
    }
    cout << min(n,ans)<<endl;


    return 0;
}
