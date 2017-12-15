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
string s999;stringstream ds999;
#define DBG(...) s999=#__VA_ARGS__;replace(ALL(s999),',',' ');ds999<<s999; debug(ds999,__VA_ARGS__);
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
    LL i,o,t,j,l,s,z;
    cin >> i>>o>>t>>j>>l>>s>>z;
    LL ans=o;
    if(j%2+l%2+i%2>1 and j>0 and l>0 and i>0){
        ans+=3;
        --j;
        --l;
        --i;
    }
    ans+=(j/2)*2+(l/2)*2+(i/2)*2;
    cout << ans <<endl;



    return 0;
}
