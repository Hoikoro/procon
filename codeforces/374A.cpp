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
    int n,ans=0,a[1000]={};
    string s;
    cin >>n>> s;
    int cnt=0;
    REP(i,n){
        //OUT(s[i])
        if(s[i]=='B'){
            a[cnt]++;
        }else if (a[cnt]!=0){
            cnt++;
        }
    }
    ans=a[cnt]==0?cnt:cnt+1;
    cout <<  ans << endl;
    REP(i,ans){
        cout << a[i];
        if(i!=ans-1)cout << ' ';
    }
    if(ans!=0)cout << endl;

    return 0;
}
