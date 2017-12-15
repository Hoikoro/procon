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
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin >> n >> a >> b;
    if(a>b) swap(a,b);
    vector<int> w(n);
    REP(i,n){
        cin >> w[i];
    }
    sort(w.begin(),w.end(),greater<int>());
    LL s[2]={};
    REP(i,a){
        s[0]+=w[i];
    }
    FOR(i,a,a+b){
        s[1]+=w[i];
    }
    cout << fixed<<setprecision(10)<<(double)s[0]/a+(double)s[1]/b <<endl;


    return 0;
}
