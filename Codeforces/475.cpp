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
int bd;
int n,s,w;

int border(int a){
    LL lower = 0,upper = 78888;
    while(upper-lower>1){
        LL mid = (lower+upper) / 2;
        if(a+50*s+250*s/(4+mid)<=bd){
            upper = mid;
        }else{
            lower = mid;
        }
    }
    return upper;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> s >> w;
    vector<int> p;
    REP(i,n) {
        int tmp;
        cin >> tmp;
        if(i==w){
            bd=tmp+s*100;
        }else{
            p.push_back(tmp);
        }
    }
    sort(ALL(p),greater<int>());
    double ans=1;
    REP(i,n-1){
        if(n-1-border(p[i])+1-i<=0){
            cout << 0.0<<endl;
            return 0;
        }else{
            ans*=((double)n-1-border(p[i])+1-i)/(n-1-i);
        }
    }
    cout << fixed <<setprecision(10) <<ans <<endl;

    return 0;
}
