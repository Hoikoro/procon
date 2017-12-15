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
    LL n,w,v,u,x,y;
    vector<pair<LL,LL>> a;

    cin >> n >> w >> v >> u;
    REP(i,n){
        cin >> x >> y;
        LL tmp=v*y-u*x;
        //OUT(tmp)
        a.push_back(make_pair(tmp,y));
    }

    sort(a.begin(),a.end());
    if(abs(a[0].first+a[n-1].first)==abs(a[0].first)+abs(a[n-1].first)){
        cout << fixed<<setprecision(12)<<((double)w/u) << endl;
    }else{
        cout << fixed<<setprecision(12)<<((double)((double)v*w-a[0].first)/((double)u*v)) << endl;
    }

    return 0;
}
