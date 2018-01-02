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
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define OUT(a) cout<<(a)<<endl;
#define ALL(v) (v).begin(), (v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=1ll<<62; const int INF=1ll<<30; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n=0,l;
    char c;
    string s; cin >> s;
    l=s.size();
    c=s[l-1];
    s.erase(l-1); --l;
    REP(i,l){
        n*=10;
        n+=s[i]-'0';
    }
    if(n%4==1) n=(n+1)/2;
    else if (n%4==2) n=n/2+1;
    else n=n/2;
    LL m=n;
    n=7*(n-1);
    n+=((m-1)/2)*2;

    if(c=='f') n+=1;
    else if(c=='e') n+=2;
    else if(c=='d') n+=3;
    else if(c=='a') n+=4;
    else if(c=='b') n+=5;
    else if(c=='c') n+=6;

    cout << n <<endl;






    return 0;
}
