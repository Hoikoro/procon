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

long long modpow(long long a, long long n){
    if(n==0) return 1;
    long long re=modpow((a*a)%MOD,n/2)%MOD;
    if(n%2==1) re= (re*a)%MOD;
    return re;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    VI a(n);
    REP(i,n) cin >> a[i];
    sort(ALL(a));
    if(a[0]==0){
        FOR(i,1,n){
            if(a[i]!=i+i%2){
                cout << 0 << endl;return 0;
            }
        }
        cout << modpow(2,n/2)<<endl;
    }else if(a[0]==1 and a[1]==1){
        FOR(i,2,n){
            if(a[i]!=i+1-(i%2)){
                cout << 0 << endl;return 0;
            }
        }
        cout << modpow(2,n/2)<<endl;
    }else{
        cout << 0 << endl;return 0;
    }


    return 0;
}
