#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    int d[101]={};
    REP(i,n){
        cin >> a[i];
        d[a[i]]++;
    }

    sort(a.begin(),a.end());
    if(d[a[0]]>2){
        cout << "Impossible" <<endl;
        return 0;
    }
    if(d[a[0]]==1){
        if(a[0]*2<a[n-1]){
        cout << "Impossible" <<endl;
        return 0;
        }
        d[a[0]]--;
        FOR(i,a[0]+1,a[n-1]+1){
            d[i]-=2;
            if(d[i]<0){
                cout << "Impossible" <<endl;
                return 0;
            }
        }
    }else{
        if(a[0]*2-1<a[n-1]){
        cout << "Impossible" <<endl;
        return 0;
        }
        d[a[0]]=0;
        FOR(i,a[0]+1,a[n-1]+1){
            d[i]-=2;
            if(d[i]<0){
                cout << "Impossible" <<endl;
                return 0;
            }
        }
    }
    cout << "Possible" <<endl;

    return 0;
}
