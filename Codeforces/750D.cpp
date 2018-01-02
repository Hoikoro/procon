#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

//make_tuple emplace_back next_permutation push_back make_pair second first
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define ALL(v) (v).begin(),(v).end()
#define SI(v) (int)(v).size()
#define endl "\n"

string dst__; stringstream dss__;
#define DBG(...) dst__=#__VA_ARGS__;replace(ALL(dst__),',',' '); dss__<<dst__; debug(dss__,__VA_ARGS__);
inline void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

//set<PI> grid;

PI vert(PI a, PI b){
    int x=b.first-a.first;
    return make_pair(a.first-x,b.second);
}
PI naname(PI a, PI b){
    int x=b.first-a.first,y=b.second-a.second;
    return make_pair(a.first+y,a.second+x);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    VI t(n);
    set<PI> cover;
    int nx=0,ny=0;
    vector<vector<PI>> q(n);
    q[0].emplace_back(0,0);
    for(int i=0; i<n; ++i){
        cin >> t[i];
        if(i==0)t[i]--;
        for(int j=0; j<t[i]; ++j){
            ++ny;
            if(i%2==1) ++nx;
            q[i].emplace_back(nx,ny);
        }
    }
    for(int i=n-1; i>=0; --i){
        for(auto p : q[i]){
            cover.insert(make_pair(p.first,p.second));
        }
        if(i==0)break;
        vector<PI> pairs;
        for(auto p : cover){
            PI tmp;
            if(i%2==0){
                tmp=naname(make_pair(q[i].begin()->FI,q[i].begin()->SE-1),p);
            }else{
                tmp=vert(make_pair(q[i].begin()->FI-1,q[i].begin()->SE-1),p);
            }
            pairs.push_back(tmp);
        }
        for(auto p : pairs){
            cover.insert(p);
        }
    }


    cout << cover.size() << endl;


    return 0;
}
