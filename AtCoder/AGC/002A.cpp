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

    LL a[2];
    REP(i,2){
        cin >>a[i];
    }

    LL ans=a[0]*a[1];
    if(ans<=0){
        cout << "Zero" << endl;

    }else if(a[1]<0){
        if((a[0]-a[1])%2==0){
            cout << "Negative" <<endl;
        }else{
            cout << "Positive"<<endl;
        }
    }else{
        cout << "Positive" <<endl;
    }

    return 0;
}
