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

void fail(){cout << -1 << endl; exit(0);}
int lcm(int a, int b){return a*b/__gcd(a,b);}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> c(n),ans,vis(n);
    REP(i,n) {
        cin >> c[i];
        c[i]--;
    }

    REP(i,n){
        if(vis[i])continue;
        vis[i]=1;
        int j=i,cnt=1;
        while(c[j]!=i){
            if(cnt>n) fail();
            vis[c[j]]=1;
            j=c[j];
            cnt++;
        }
        if(cnt%2==0)cnt/=2;
        ans.push_back(cnt);
    }
    int ret=1;
    REP(i,ans.size()){
        ret=lcm(ret,ans[i]);
    }
    cout << ret << endl;
    return 0;
}
