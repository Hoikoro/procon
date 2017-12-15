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
    cin >> n;
    priority_queue<PI> bid;
    vector<int> vis(n+1,0);
    vector<PI> ord;
    vector<vector<int>> t(n+1);
    REP(i,n){
        int a,b;
        cin >> a>> b;
        bid.push(MP(b,a));
        t[a].push_back(b);
    }
    FOR(i,1,n+1)sort(ALL(t[i]));
    while(!bid.empty()){
        PI tmp=bid.top();
        bid.pop();
        if(vis[tmp.SE]==0){
            ord.push_back(tmp);
            vis[tmp.SE]=1;
        }
    }
    cin >> q;
    REP(i,q){
        int r,winner,nex;
        cin >>r;
        set<int> rem;
        REP(j,r){
            int tmp;
            cin >> tmp;
            rem.insert(tmp);
        }
        winner=0;
        nex=0;
        bool f=false;
        REP(j,ord.size()){
            if(!f and rem.count(ord[j].SE)) {winner=j+1;nex=j+1;}
            else if(f and rem.count(ord[j].SE)) nex=j+1;
            else if(!f) {f=true;nex=j+1;}
            else break;
        }
        if(winner==ord.size()){
            cout << 0 << ' '<< 0 <<endl;
            continue;
        }
        cout << ord[winner].SE <<' ';
        int win=(nex==ord.size())?*(t[ord[winner].SE].begin()):(*upper_bound(ALL(t[ord[winner].SE]),ord[nex].FI));
        cout << win<<endl;
    }

    return 0;
}
