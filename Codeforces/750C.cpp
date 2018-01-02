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

void fail(){cout << "Impossible" << endl; exit(0);}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>> n;
    VI d(n),c(n);
    for(int i=0; i<n; ++i){
        cin >> c[i] >> d[i];
    }
    int l=-INF,h=INF,sum=0;
    if(d[0]==1 )l=1900;
    if(d[0]==2 )h=1899;
    for(int i=0; i<n-1; ++i){
        if(d[i]==1 and d[i+1] == 2 and c[i]>=0) fail();
        if(d[i]==2 and d[i+1] == 1 and c[i]<=0) fail();
        if(d[i]==1){
            l=max(l,1900-sum);
            if(d[i+1]==2){
                h=min(h,1899-sum-c[i]);
            }else{
                l=max(l,1900-sum-c[i]);
            }
        }
        if(d[i]==2){
            h=min(h,1899-sum);
            if(d[i+1]==1){
                l=max(l,1900-sum-c[i]);
            }else{
                h=min(h,1899-sum-c[i]);
            }
        }
        sum+=c[i];
    }
    if(h<l)fail();
    if(h==INF){
        cout << "Infinity"<<endl;
        return 0;
    }
    cout << h+sum+c[n-1] <<endl;


    return 0;
}
