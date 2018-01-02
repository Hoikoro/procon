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

typedef long long LL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n)-1)
#define FOR(i,a,b) for(int (i)=(a); (i)<=(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,s[1<<18]={};
    cin >> n;
    REP(i,n){
        char a;
        LL b;
        cin >> a >> b;
        int tmp=0;
        for(int i=0; b>0;i++){
            tmp+=(b%2)<<i;
            b/=10;
        }
        //OUT(tmp)
        if(a=='+') s[tmp]++;
        else if(a=='-') s[tmp]--;
        else{
            cout << s[tmp] <<endl;
        }

        }

    return 0;
}
