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

void permutationConv(vector<LL> &b,vector<LL> &f){
    vector<int> t(b.size());
    REP(i,b.size()) t[i]=b[f[i]];
    REP(i,b.size()) b[i]=t[i];
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    LL k;
    cin >> n;
    vector<LL> x(n), dx(n-1),r(n-1),r2(n-1);
    vector<vector<LL>> to(62,vector<LL>(n-1));
    REP(i,n) cin >> x[i];
    REP(i,n-1) {
        dx[i]=x[i+1]-x[i];
        r[i]=i;
    }
    cin >> m>>k;
    vector<LL> jmp(m);
    REP(i,m){
        cin >> jmp[i];
    }
    REP(i,m) swap(r[jmp[i]-2],r[jmp[i]-1]);
    REP(i,n-1) to[0][i]=r[i];
    //REP(j,n-1)DBG(to[0][j])
    FOR(i,1,61){
        REP(j,n-1) to[i][j]=j;
        REP(j,2) permutationConv(to[i],to[i-1]);
        //cerr << " "<<i << endl;
        //REP(j,n-1)DBG(to[i][j])
    }
    REP(i,n-1) r[i]=i;
    for(LL i=k,j=0; i>0; i/=2,++j){
        if(i%2==1){
            permutationConv(r,to[j]);
        }
    //REP(i,n-1)DBG(r[i])
    }
    //REP(i,n-1)r2[r[i]]=dx[i];
    //REP(i,n-1)DBG(r2[i])
    REP(i,n-1)x[i+1]=x[i]+dx[r[i]];

    cout << fixed << setprecision(10);
    REP(i,n)cout << (double)x[i] <<endl;

    return 0;
}
