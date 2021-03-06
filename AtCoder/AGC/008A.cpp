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

//make_tuple emplace_back next_permutation
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(...) string s999=#__VA_ARGS__;replace(ALL(s999),',',' ');stringstream ds999; ds999<<s999; debug(ds999,__VA_ARGS__);
inline void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<' '<<f<<' '; debug(ds,r...);}
#define ALL(v) (v).begin(),(v).end()
#define SI(v) (int)(v).size()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x,y,ans=2e9+10;
    cin >> x >> y;
    /*if(x>=0 and y>x) ans=y-x;
    else if (x>=0 and 0<=y and y<x) ans=x-y+2;
    else if(x>=0 and y<0)ans=min(x-y);
*/
    if(abs(x)<=abs(y))ans=min(ans,abs(y)-abs(x)+(abs(x)==x?0:1)+(abs(y)==y?0:1));
    if(1)ans=min(ans,abs(x)+abs(y)+(abs(x)==x?0:1)+(-abs(y)==y?1:0));
    if(-abs(x)<=-abs(y))ans=min(ans,abs(x)-abs(y)+(-abs(x)==x?0:1)+(-abs(y)==y?0:1));
    cout << ans<<endl;

    return 0;
}
