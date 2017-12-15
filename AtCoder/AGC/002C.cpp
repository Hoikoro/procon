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

    LL n,l,a[100010];
    int last=-1;

    cin >> n >> l;
    cin >>a[1];
    FOR(i,2,n+1){
        cin >> a[i];
        if((a[i]+a[i-1]>=l)){
            last=i-1;
        }
    }
    if(last==-1){
        cout << "Impossible" << endl;
        return 0;
    }else{
        cout << "Possible" <<endl;
        FOR(i,1,last){
            cout << i <<endl;
        }
        for(int i=n-1;i>=last ;--i){
            cout << i << endl;
        }
    }

    return 0;
}
