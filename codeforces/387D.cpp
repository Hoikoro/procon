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
#define debug(a) cerr<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int days,k,cnt=0,s=0,ans=0;
    cin >> days >> k;
    VI t(days),nn;
    REP(i,days){
        cin >> t[i];
        if(t[i]<0){
            if(cnt>0 and s!=0)nn.push_back(s);
            cnt++;
            s=0;
            if(i==0 or t[i-1]>=0) ++ans;
        }else{
            ++s;
            if(i!=0 and t[i-1]<0) ++ans;
        }
    }
    if(cnt>k){cout << -1 << endl; return 0;}
    if(cnt==0){cout << 0 << endl;return 0;}
    sort(ALL(nn));
    int res=k-cnt;
    REP(i,nn.size()){
        if(res-nn[i]>=0){
            res-=nn[i];
            ans-=2;
        }
    }
    if(s!=0 and res>=s)ans-=1;
    cout << ans <<endl;
    return 0;
}
