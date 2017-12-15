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
    int n,m,a[110],cnt=0;
    vector<int> ans;

    cin >> n >> m;
    REP(i,m){
        cin >> a[i];
        if(a[i]%2==1) {
            swap(a[i],a[cnt]);
            cnt++;
        }
    }

    if(cnt>2){
        cout << "Impossible" <<endl;
        return 0;
    }
    if(m!=1)swap(a[1],a[m-1]);
    REP(i,m-1) cout << a[i] <<' ';
    cout << a[m-1]<<endl;
    if(m==1){
        a[1]=0;
        m=2;
    }
    cout << (a[0]>1?m:m-1) <<endl;
    REP(i,m-1){
        if(i==0) {if(a[0]>1) cout <<a[i]-1<<' ';}
        else cout << a[i] <<' ';
    }
    cout << a[m-1]+1<<endl;



    return 0;
}
