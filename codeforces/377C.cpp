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

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<LL> b(3),bb(3);
    LL ans=1ll<<62;
    cin >> b[0] >>b[1] >>b[2];
    REP(i,8){
        bb[0]=b[0]-i/4;
        bb[1]=b[1]-(i%4)/2;
        bb[2]=b[2]-i%2;
        sort(bb.begin(),bb.end());
        ans=min(ans,bb[2]-bb[1]+bb[2]-bb[0]);
    }
    cout << ans <<endl;

    return 0;
}
