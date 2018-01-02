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
    LL n;
    cin >> n;
    vector <LL> r;
    REP(i,n){
        LL tmp;
        cin >> tmp;
        r.push_back(tmp);
    }
    sort(r.begin(),r.end());
    r.erase(unique(r.begin(),r.end()),r.end());

    if(r.size()>3){
        cout << "NO" <<endl;
    }else if(r.size()<=2){
        cout << "YES" <<endl;
    }else{
        if(r[2]+r[0]-r[1]*2==0){
            cout << "YES" <<endl;
        }else{
            cout << "NO" <<endl;
        }
    }

    return 0;
}
