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
//emplace_back next_permutation tie get

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
    string a,b,t[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday","sunday"};
    int aa,bb,tt;

    cin >> a >> b;
    REP(i,7){
        if(a==t[i]) aa=i;
        if(b==t[i]) bb=i;
    }
    tt=(bb-aa+7)%7;
    if(tt==0 or tt==2 or tt==3) cout <<"YES" <<endl;
    else cout << "NO" <<endl;

    return 0;


}
