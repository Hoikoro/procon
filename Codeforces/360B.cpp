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

int n,hi[110];
int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    scanf("%d",&n);
    REP(i,n){
        scanf("%d",&hi[i]);
    }
    REP(j,n-1){
    REP(i,n-1-j){
        if(hi[i]>hi[i+1]){
            printf("%d %d\n",i+1,i+2);
            swap(hi[i],hi[i+1]);
        }
    }
    }

    return 0;
}
