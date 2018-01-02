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

int city[110],crim[110],ans,n,a;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> a;
    FOR(i,1,1+n){
        city[abs(i-a)]++;
        int tmp;
        cin >>tmp;
        crim[abs(i-a)]+=tmp;
    }
    REP(i,101){
        if(city[i]==crim[i]){
            ans+=crim[i];
        }
    }
    cout<< ans << endl;

    return 0;
}
