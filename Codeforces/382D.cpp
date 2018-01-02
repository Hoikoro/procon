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
bool check(LL a){
    for(LL i=2;i*i<=a;++i){
        if(a%i==0)return false;
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,ans=0;
    cin >> n;
    if(n==2){
        ans=1;
    }else if(n%2==0){
        ans=2;
    }else{
        if(check(n))ans=1;
        else if(check(n-2)) ans=2;
        else ans=3;
    }
    cout <<ans <<endl;


    return 0;
}
