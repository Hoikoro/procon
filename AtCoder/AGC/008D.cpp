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

//make_tuple emplace_back next_permutation
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(...) string s999=#__VA_ARGS__;replace(ALL(s999),',',' ');stringstream ds999; ds999<<s999; debug(ds999,__VA_ARGS__);
inline void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<' '<<f<<' '; debug(ds,r...);}
#define ALL(v) (v).begin(),(v).end()
#define SI(v) (int)(v).size()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;
void fail(){cout <<"No"<<endl; exit(0);}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<PI> a;
    FOR(i,1,n+1) {
        int tmp;
        cin >> tmp;
        a.push_back(make_pair(tmp,i));
    }
    VI ans,cnt(n+1),rank(n+1);
    queue<int> t,ne;
    sort(ALL(a));
    REP(i,n) {
        rank[a[i].SE]=i+1;
    }
    REP(i,n){
        REP(j,a[i].SE-1)ne.push(a[i].SE);
        cnt[a[i].SE]=a[i].SE-1;
    }
    a.insert(a.begin(),MP(0,0));

    REPN(i,1,n){
        REP(j,a[i].FI-a[i-1].FI-1){
            //DBG(t.size())
            if(!ne.empty()){
                ans.push_back(ne.front());
                ne.pop();
            }else{
                if(t.empty()){
                    //cout << 'A'<<endl;
                    fail();
                }
                ans.push_back(t.front());
                t.pop();
            }
        }
        //DBG(ne.front(), a[i].SE)
        if(!ne.empty() and rank[ne.front()]<=rank[a[i].SE]){
            //cout << 'B'<<endl;
            fail();
        }
        ans.push_back(a[i].SE);
        REP(j,n-a[i].SE)t.push(a[i].SE);
    }
    //DBG(a[n].SE)
    FOR(i,a[n].FI,n*n){
            ans.push_back(t.front());
                t.pop();
    }
    cout << "Yes"<<endl;
    REP(i,ans.size()-1)cout << ans[i]<<' ';
    cout << ans[ans.size()-1]<<endl;


    return 0;
}
