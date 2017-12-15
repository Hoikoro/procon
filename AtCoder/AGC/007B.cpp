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
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >>n;
    vector<int> a(n),b(n),p(n+1);
    REP(i,n){
        int tmp; cin >> tmp;
        p[tmp]=i;
    }
    REP(i,n){
        a[i]=50000*i+1;
        b[i]=50000*(n-1-i)+p[i+1]+1;
    }
    REP(i,n)cout << a[i]<< (i==n-1?'\n':' ');
    REP(i,n)cout << b[i]<<(i==n-1?'\n':' ');

    return 0;
}
