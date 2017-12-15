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

void out(vector<int> &a){
    REP(i,3){
        REP(j,3){
            if(a[j]>i)cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,n;
    cin >> h >> w >> n;
    VI field(w),cnt(n);
    vector<vector<PI>> c(w);
    vector<VI> ans(n,VI(3));
    REP(i,h){
        string s;
        cin >> s;
        REP(j,w) if(s[j]=='#') field[j]++;
    }
    REP(i,n){
        int tmp; cin >>tmp;
        FOR(j,tmp,tmp+3){
            c[j].emplace_back(j-tmp,i);
        }
    }
    REP(i,w)sort(ALL(c[i]),greater<PI>());
    REP(i,w){
        for(int j=0; j<c[i].size();++j){
            auto &b=c[i][j];
            if(cnt[b.SE]==0){
                ans[b.SE][b.FI]=min(field[i],max(1,field[i]-3*((int)c[i].size()-j-1)));
            }else{
                ans[b.SE][b.FI]=max(0,field[i]-3*((int)c[i].size()-j-1));
            }
            cnt[b.SE]+=ans[b.SE][b.FI];
            field[i]-=ans[b.SE][b.FI];
        }
    }
    REP(i,n) out(ans[i]);

    return 0;
}
