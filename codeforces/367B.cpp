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
    vector<int> p;
    int n,t;
    cin >> n;
    REP(i,n){
        cin >>t;
        p.push_back(t);
    }
    sort(p.begin(),p.end());
    int q;
    cin >>q;
    REP(i,q){
        cin >> t;
        OUT(upper_bound(p.begin(),p.end(),t)-p.begin())
    }

    return 0;
}
