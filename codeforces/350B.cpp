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

    LL n,k,t,id[100010]={};
    cin >> n >> k;
    REP(i,n){
        cin >> id[i];
    }
    k--;
    LL lower = 0,upper = 1100000;
    for(int i=0;i<200;i++){
    LL m = (lower+upper) / 2;
    if(m*(m+1)/2>k){
        upper = m;
    }else{
        lower = m;
    }
    t=m;
    }


    cout<< id[k-t*(t+1)/2] <<endl;

    return 0;
}
