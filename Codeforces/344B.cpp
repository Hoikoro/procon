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
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    int n,m,k,p,q,r;
    scanf("%d %d %d",&n ,&m, &k);
    vector< vector<int> > a(n, vector<int>(m, 0));
    REP(i,k){
        scanf("%d %d %d",&p ,&q, &r);
        if(p==1){
            fill(a[q-1].begin(),a[q-1].end(),r);
        }else{
            REP(j,n){
                a[j][q-1]=r;
            }
        }
    }
    REP(i,n){
        REP(j,m-1){
            printf("%d ",a[i][j]);
        }
        printf("%d\n", a[i][m-1]);
    }

    return 0;
}
