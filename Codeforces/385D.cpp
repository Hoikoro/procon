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
    int n;
    cin >> n;
    int loop=0;
    int tmp=1;
    while(1){
        tmp*=2;
        loop++;
        if(n<=tmp) break;
    }
    VI ans(n,INF);
    //dump(loop)
    REP(i,loop){
        vector<int>a,b;
        for(int j=n-1;j>=0;--j){
            if((j>>i)&1)a.push_back(n-j);
            else b.push_back(n-j);
        }
        cout << a.size()<<endl;
        fflush(stdout);

        REP(j,a.size()-1){
            cout << a[j]<<' ';
            fflush(stdout);
        }
        cout << a[a.size()-1]<<endl;
        fflush(stdout);

        REP(j,n){
            int tmp;
            cin >> tmp;
            if((((n-1-j)>>i)&1)==0){
                ans[j]=min(ans[j],tmp);
            }
        }

        cout << b.size()<<endl;
        fflush(stdout);
        REP(j,b.size()-1){
            cout << b[j]<<' ';
            fflush(stdout);
        }
        cout << b[b.size()-1]<<endl;
        fflush(stdout);

        REP(j,n){
            int tmp;
            cin >> tmp;
            if((((n-1-j)>>i)&1)==1){
                ans[j]=min(ans[j],tmp);
            }
        }

    }

    cout << -1 <<endl;
    fflush(stdout);
    REP(j,ans.size()-1){
        cout << ans[j]<<' ';
        fflush(stdout);
    }
    cout << ans[n-1]<<endl;




    return 0;
}
