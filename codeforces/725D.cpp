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
#define OUT(a) cout<<(a)<<endl;
#define ALL(v) (v).begin(), (v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=1ll<<62; const int INF=1ll<<30; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,pos=1,dq=0;
    vector<pair<LL,LL>> v; //<left,bal>
    priority_queue<LL,vector<LL>,greater<LL>> P;
    LL t1,t2,bal;
    cin >>n;
    cin >> bal >>t1;
    REP(i,n-1){
        cin >> t1>>t2;
        if(t1>bal){
            ++pos;
            P.push(t2-t1+1);
        }
        v.PB(MP(t1,t2));
    }
    int ans=pos;
    sort(v.rbegin(),v.rend());
    //OUT(ans)
    while(!P.empty()){
        //OUT(P.top())
        if(P.top()>bal) break;
        bal-=P.top();
        ++dq;
        P.pop();
        while(pos!=n && v[pos-1].first>bal){
            P.push(v[pos-1].second-v[pos-1].first+1);
            ++pos;
        }
        //OUT(bal)
        //cout << pos <<' ' <<dq<<endl;
        ans=min(ans,pos-dq);
    }
    cout << ans <<endl;






    return 0;
}
