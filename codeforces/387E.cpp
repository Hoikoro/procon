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
int maxd;
vector<vector<string>> ans(600000);
stringstream ss;

void reader(int l, int d){
    if(d>maxd) maxd=d;
    string a; int b;
    REP(i,l){
        if(ss >> a >> b){
            ans[d].push_back(a);
            reader(b,d+1);
        }else return;

    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    replace(ALL(s),',',' ');
    ss<<s;
    reader(260000,0);

    cout << maxd<<endl;
    REP(i,maxd){
        REP(j,ans[i].size()-1)cout << ans[i][j]<<' ';
        cout << ans[i][ans[i].size()-1]<<endl;
    }

    return 0;
}
