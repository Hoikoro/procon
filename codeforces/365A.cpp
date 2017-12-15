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
    int n,m=0,c=0;
    cin >> n;
    REP(i,n){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        if(tmp1>tmp2) m++;
        if(tmp1<tmp2) c++;
    }

    if(m>c){
        cout << "Mishka" <<endl;
    }else if ( m< c){
        cout << "Chris" <<endl;
    }else{
        cout <<"Friendship is magic!^^"<<endl;
    }

    return 0;
}
