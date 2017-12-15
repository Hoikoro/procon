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

    int n;
    cin >> n;
    LL x,time[2020]={},m[2020];
    vector<vector<pair<int,LL>>> a(n);
    cin >> x;
    REP(i,n){
        cin >> time[i];
        m[i]=time[i];
        a[i].push_back(make_pair(0,m[i]));
    }
    REPN(i,1,n-1){
        REP(j,n){
            m[j]=min(m[j],time[(j-i+n)%n]);
            a[j].push_back(make_pair(i,m[j]));
        }
    }
    LL ans=2E18;
    REP(i,n){
        LL tmp=0;
        REP(j,n){
            tmp+=(a[j].begin()+i)->second;
        }
        ans=min(ans,tmp+x*i);
    }

    cout << ans <<endl;


    return 0;
}
