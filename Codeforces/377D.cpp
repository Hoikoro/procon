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

int n,m,e[100010]={},a[100010]={},chk[100010];
vector<pair<int,int>> b;

bool check(int c){
    LL used=0;
    b.clear();
    REPN(i,1,n) chk[i]=0;
    for(int i=c;i>=1;--i){
        if(e[i]!=0 and chk[e[i]]==0) chk[e[i]]=i;
    }
    REPN(i,1,m){
        if(chk[i]==0) return false;
        b.PB(MP(chk[i],a[i]));
    }
    sort(b.begin(),b.end());
    REP(i,m){
        used+=b[i].SE;
        if(used>=b[i].FI) return false;
        ++used;
    }
    return true;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    REPN(i,1,n){
        cin >> e[i];
    }
    REPN(i,1,m){
        cin >> a[i];
    }

    int lower = 1,upper = n+1;
    for(int i=0;i<200;i++){
        int mid = (lower+upper) / 2;
        if(check(mid)){
            upper = mid;
        }else{
            lower = mid;
        }
    }

    if(upper==n+1) cout << -1 <<endl;
    else cout << upper <<endl;


    return 0;
}
