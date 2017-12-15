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
#include <bitset>
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
    int n,a[110];  cin >> n;
    REP(i,n){
        cin >> a[i];
    }

    int tot=1E9;

    FOR(i,-100,101){
        int tt=0;
        REP(j,n){
            tt+=(a[j]-i)*(a[j]-i);
        }
        if(tt<tot){

            tot=tt;
        }
        //OUT(tt)
    }
    cout << tot << endl;
    return 0;
}
