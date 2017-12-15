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
    int n,cnt;
    string s;
    cin >>n>> s;
    cnt=n;
    set<int> d,r;
    set<pair<int,char>> w;
    REP(i,s.size()){
        if(s[i]=='D')d.insert(i);
        else r.insert(i);
        w.insert(MP(i,s[i]));
    }

    while(d.size()>0 and r.size()>0){
        for(auto it = w.begin();it!=w.end();++it){
            if(it->second=='D'){
                if(r.size()==0){cout << 'D' <<endl;return 0;}
                auto deny=r.lower_bound(it->first);
                if(deny==r.end())deny=r.begin();
                w.erase(MP(*deny,'R'));
                r.erase(deny);
            }
            if(it->second=='R'){
                if(d.size()==0){cout << 'R' <<endl;return 0;}
                auto deny=d.lower_bound(it->first);
                if(deny==d.end())deny=d.begin();
                w.erase(MP(*deny,'D'));
                d.erase(deny);
            }
        }
    }
    if(d.size()==0)cout << 'R'<<endl;
    else cout << 'D'<<endl;



    return 0;
}
