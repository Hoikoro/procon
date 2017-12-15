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
    cin >> n >>q;
    vector<VLL> h(n+1,VLL(3));
    map<VLL,int> m;

    LL b[3]={149853437,2345752,564565},p[3]={999999937,MOD,MOD+2};
    h[0]={0,0,0};
    h[1]={1,1,1};
    FOR(i,2,n+1){
        REP(j,3){
            h[i][j]=h[i-1][j]*b[j]%p[j];
        }
    }
    FOR(i,2,n+1){
        REP(j,3){
            h[i][j]=(h[i][j]+h[i-1][j])%p[j];
        }
    }
    VLL st(3);
    m[st]=0;
    REP(i,q){
        char op;cin >>op;
        if(op=='!'){
            int l,r,k;
            cin >> l >> r >> k;
            LL add[3];
            REP(j,3){
                add[j]=(h[n-l][j]-h[n-r][j]+p[j])%p[j];
                st[j]=(st[j]+add[j]*((k+p[j])%p[j]))%p[j];
            }
            if(m.count(st)==0)m[st]=i+1;
        }if(op=='?'){
            cout << m[st] <<endl;
        }
    }

    return 0;
}
