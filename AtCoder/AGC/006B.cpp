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
    int n,x,ans[200002]={},used[200002]={};
    cin >> n >> x;
    if(x==1 || x==2*n-1){
        cout << "No" <<endl;
        return 0;
    }else if(n==2){
        REPN(i,1,3)ans[i]=i;
    }else{
        ans[n]=x;
        int t=(x==2*n-2?-1:1);
        ans[n-1]=x+t;
        ans[n+1]=x-t;
        ans[n+2]=x+2*t;
        REPN(i,-1,3)used[x+i]=1;
        used[x+2*t]=1;

        int j=1;
        REPN(i,1,n-2){
            while(used[j])j++;
            ans[i]=j;
            used[j]=1;
        }
        FOR(i,n+3,2*n){
            while(used[j])j++;
            ans[i]=j;
            used[j]=1;
        }
    }
    cout << "Yes" <<endl;
    REPN(i,1,2*n-1) cout << ans[i] <<endl;

    return 0;
}
