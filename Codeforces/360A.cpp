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

LL ice;
int n,x,dist,tmp;
char dis;

int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    scanf("%d %d\n",&n ,&x);
    ice=x;
    REP(i,n){
        scanf("%c %d\n",&dis,&tmp);
        if(dis=='+'){
            ice+=tmp;
        }else if(ice>=tmp){
            ice-=tmp;
        }else{
            ++dist;
        }
        //OUT(i)
        //OUT(dist)
        //OUT(ice)
    }

    printf("%lld %d\n",ice,dist);


    return 0;
}
