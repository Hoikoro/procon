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
    int a[1100]={},b[1100]={},n,tmpa,tmpb,ans=0,d=1;
    cin >> n;
    REP(i,n){
        cin>> a[i];
    }
    REP(i,n){
        cin >> b[i];
    }
    REP(i,30){
        int tmp=0;
        REP(i,n){
            tmpa=a[i]%2;
            a[i]/=2;
            tmp=max(tmp,tmpa);
        }
        ans+=d*tmp;
        tmp=0;
        REP(i,n){
            tmpb=b[i]%2;
            b[i]/=2;
            tmp=max(tmp,tmpb);
        }
        ans+=d*tmp;
        d*=2;
    }
    cout << ans <<endl;

    return 0;
}
