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
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,a[100];
    cin >> n;
    REP(i,n){
        cin >> a[i];
    }
    if(n==1){
        if(a[0]!=0 &&a[0]!=15){
            cout << -1 << endl;
            return 0;
        }else if(a[0]==0){
            cout << "UP" << endl;
            return 0;
        }else{
            cout << "DOWN" << endl;
            return 0;
        }
    }else{
        if(a[n-1]>a[n-2]){
            if(a[n-1]!=15){
                cout << "UP" << endl;
            }else{
                cout << "DOWN" << endl;
            }
        }else{
            if(a[n-1]!=0){
                cout << "DOWN" << endl;
            }else{
                cout << "UP" << endl;
            }
        }
    }


    //cout << << endl;

    return 0;
}
