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

PLL add(PLL a, PLL b){
    LL den=a.SE*b.SE;
    LL num=a.FI*b.SE+a.SE*b.FI;
    return MP(num,den);
}
bool comp(PLL a, PLL b){
    return a.FI*b.SE<a.SE*b.FI;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<PLL>> l(3);
    vector<PLL> sum,mi;
    REP(i,n){
        LL a,b,c;
        cin >> a >>b >> c;
        LL g=__gcd(b,c);
        l[a].emplace_back(b/g,(b+c)/g);
    }
    REP(i,3)l[i].emplace_back(1,1);
    sort(ALL(l[2]),comp);
    LL ans=0;
    REP(i,l[0].size()){
        REP(j,l[1].size()){
            PLL t=add(l[0][i],l[1][j]);
            if(t.SE>t.FI) continue;
            assert(t.SE>0);
            assert(t.FI>0);
            PLL mi=comp(l[0][i],l[1][j])?l[0][i]:l[1][j];
            LL point=upper_bound(ALL(l[2]),MP(2*t.SE-t.FI,t.SE),comp)-lower_bound(ALL(l[2]),MP(2*t.SE-t.FI,t.SE),comp);
            LL outside=lower_bound(ALL(l[2]),MP(mi.SE-mi.FI,mi.SE),comp)-l[2].begin();
            ans+=l[2].size()-point-outside;
        }
    }
    cout << ans <<endl;
    return 0;
}
