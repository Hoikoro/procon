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
    int n,m;
    cin >> m >> n;
    vector<VI> res(m+2,VI(n+2));
    REP(i,m){
        REP(j,n){
            cin >> res[i+1][j+1];
        }
    }
    int ans=INF;
    REP(i,(1<<(m+n-1))){
        vector<VI>flip(m+2,VI(n+2));
        int cnt=0;
        REP(j,n) flip[1][j+1]=((i>>j)&1);
        FOR(j,1,m) flip[j+1][1]=((i>>(n+j-1))&1);
        FOR(j,1,m+1){
            FOR(k,1,n+1){
                flip[j+1][k+1]=res[j][k];
                REP(h,3){
                    REP(g,(h==2?2:3)){
                        flip[j+1][k+1]^=flip[j-1+h][k-1+g];
                    }
                }
                cnt+=flip[j+1][k+1];
                if((j==m or k==n)and flip[j+1][k+1]==1) cnt=INF;
            }
        }
        cnt+=__builtin_popcount(i);
        ans=min(ans,cnt);
    }
    if(ans==INF)cout << "Impossible"<<endl;
    else cout << ans <<endl;

    return 0;
}
