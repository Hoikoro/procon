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
int n;
int chk(int p, vector<int> &d){
    int a[3];
    a[0]=(p-2+2*n)%(2*n);
    a[1]=(a[0]+1)%(2*n);
    a[2]=(a[1]+1)%(2*n);
    REP(i,3){
        if(d[a[0]]!=-1&&d[a[1]]!=-1&&d[a[2]]!=-1 && d[a[0]]==d[a[1]]&&d[a[1]]==d[a[2]]) return a[0];
        REP(j,3)a[j]=(a[j]+1)%(2*n);
    }
    return -1;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> a(n),b(n),p(2*n),d(2*n);
    REP(i,n){
        cin >> a[i]>>b[i];
        a[i]--;b[i]--;
        p[a[i]]=b[i];
        p[b[i]]=a[i];
    }
    fill(d.begin(),d.end(),-1);
    d[0]=0;d[1]=1;
    FOR(i,2,2*n-2){
        if(d[i]!=-1){
            if(d[i]==d[i-1]&& d[i]==d[i-2]){
                d[i-1]=(1-d[i-1]);
                p[d[i-1]]=1-p[d[i-1]];
            }

        }
        if(d[i-2]==d[i-1])d[i]=d[i-1]^1;
        else d[i]=(1-d[i-1]);
    }



    return 0;
}
