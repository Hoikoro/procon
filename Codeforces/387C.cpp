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
    int n,q;
    cin >> n >>q;
    VI t(n),s(n),d(n);
    priority_queue<PI,vector<PI>,greater<PI>> used;
    priority_queue<int,VI,greater<int>> aval;
    REP(i,n) aval.push(i+1);
    REP(i,q){
        int now, s,t,ans=0;
        cin >> now >> s >>t;
        while(!used.empty()){
            if(used.top().FI>now) break;
            aval.push(used.top().SE);
            used.pop();
        }
        if(aval.size()<s){
            cout << -1 << endl;
        }else{
            REP(j,s){
                ans+=aval.top();
                used.push(make_pair(now+t,aval.top()));
                aval.pop();
            }
            cout << ans<<endl;
        }

    }


    return 0;
}
