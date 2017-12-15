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
    int m,n,a[2002]={},num[2002]={},mini,ans=0;
    queue<int> b;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> P;
    cin >> n >>m;
    mini=n/m;
    REPN(i,1,n){
        cin >> a[i];
        if(a[i]<=m){
            num[a[i]]++;
            if(num[a[i]]>mini) P.push(make_pair(a[i],i));
        }else{
            num[0]++;
            P.push(make_pair(0,i));
        }
    }
    REPN(i,1,m){
        int tmp=max(0,mini-num[i]);
        ans+=tmp;
        REP(j,tmp) b.push(i);
    }
    cout << mini << ' '  << ans<<endl;

    while(!b.empty()){
        int x=P.top().first;
        int y=P.top().second;
        int z=b.front();
        a[y]=z;
        P.pop();
        b.pop();
    }
    REPN(i,1,n-1){
        cout << a[i]<<' ';
    }cout << a[n]<<endl;

    return 0;
}
