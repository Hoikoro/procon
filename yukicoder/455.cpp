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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,sh[2],sw[2];
    cin >> h >> w;
    vector<string> s(h);
    REP(i,h) cin >> s[i];
    int cnt=0;
    REP(i,h){
        REP(j,w){
            if(s[i][j]=='*'){
                sh[cnt]=i;
                sw[cnt]=j;
                cnt++;
            }
        }
    }
    if(sh[0]==sh[1]){
        s[(sh[0]+1)%h][sw[0]]='*';
    }else{
        s[sh[0]][(sw[0]+1)%w]='*';
    }
    REP(i,h)cout << s[i]<<endl;

    return 0;
}
