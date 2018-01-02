#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>
#include <numeric>
using namespace std;

typedef long long LL; typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,k,s=0,caps=0,c[100100]={},ans,capital[100100]={};


    cin >> n>> k;
    cin >> c[0];
    s+=c[0];

    REPN(i,1,n-1){
        cin >> c[i];
        s+=c[i];
        ans+=c[i]*c[i-1];
    }
    ans+=c[n-1]*c[0];
    //OUT(ans)

    REP(i,k){
        int cap;
        cin >> cap;
        capital[--cap]=1;
        ans+=(s-c[cap]-c[(cap-1+n)%n]*(1-capital[(cap-1+n)%n])-c[(cap+1)%n]-caps)*c[cap];
        caps+=c[cap];
    }
    ans+=capital[0]*capital[n-1]*c[0]*c[n-1];
    cout << ans << endl;

    return 0;
}
