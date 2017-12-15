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
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,cnt[101]={},mini=0,maxi=0;
    cin >>n >>k;
    string s[110],correct;
    REP(i,n){
        cin >> s[i];
        cnt[s[i].size()]++;
    }
    cin >> correct;
    REPN(i,1,correct.size()-1){
        mini+=cnt[i];
    }
    maxi=mini+cnt[correct.size()];
    mini++;
    mini=mini+((mini-1)/k)*5;
    maxi=maxi+((maxi-1)/k)*5;
    cout << mini << ' ' <<maxi <<endl;
    return 0;
}
