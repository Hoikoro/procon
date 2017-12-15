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


//vector<LL> d(n+2,0),revd(n+2,0);
int r[200020]={},l[200020]={},n;
void dp(int a[],vector<LL> &d){
    REPN(i,1,n){
        for(int j=i-1;j>=0;--j){
            if(d[j]<d[i]){
                a[i]=j;
                break;
            }
            j=a[j]+1;
            continue;
        }
    }
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL ans=0;
    //int n;
    cin >>n;
    vector<LL> d(n+2,0),revd(n+2,0);
    //int r[200020]={},l[200020]={};
    REP(i,n){
        cin >>d[i+1];
        revd[n-i]=d[i+1];
    }

    dp(l,d);
    dp(r,revd);

    REPN(i,1,n){
        ans+=d[i]*(i-l[i])*((n+1-r[n+1-i])-i);
    }
    cout << ans <<endl;


    return 0;
}
