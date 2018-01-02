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
#define DBG(...) string s999;s999=#__VA_ARGS__;replace(ALL(s999),',',' ');stringstream ds999; ds999<<s999; debug(ds999,__VA_ARGS__);
inline void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<' '<<f<<' '; debug(ds,r...);}
#define ALL(v) (v).begin(),(v).end()
#define SI(v) (int)(v).size()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

VLL divisor;
LL n,x;
map<tuple<int,LL,LL>,int> dp;
void pre(long long k){
    for(long long  i=2; ;++i){
        if(i*i>k){
            break;
        }
        if(k%i==0){
            divisor.push_back(i);
            if(i*i<k)divisor.push_back(k/i);
        }
    }
    return;
}

int calc(int a, LL m, LL p){
    int ret=0;
    auto it=dp.find(make_tuple(a,m,p));
    if(it!=dp.end()){
        return it->second;
    }
    if(a==n-1){
        if(x/p>=divisor[m] and x%(x/p)==0) return 1;
        else return 0;
    }
    for(auto it = divisor.begin()+m; it<divisor.end(); ++it){
        //DBG(p,*it,log(x/p)/log(*it),(double)n-a+1)
        if(log(x/p)/log(*it)<(double)n-a-1)break;
        if((x/p)%*it==0) ret+=calc(a+1,it-divisor.begin(),p*(*it));
    }
    return dp[make_tuple(a,m,p)]=ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> x;
    ++x;
    pre(x);
    sort(ALL(divisor));
    if(divisor.size()==0) cout << 0 <<endl;
    else cout << calc(0,0,1)<<endl;

    return 0;
}
