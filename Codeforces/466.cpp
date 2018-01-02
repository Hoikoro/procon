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
#include <random>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define dump(a) cerr<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c,d,n,m;
    cin >> a >> b >> c >> d;
    if(a==1 and b==1 and c==1 ){
        cout << -1 <<endl;
        return 0;
    }
    n=a+b-c;
    if(c==0)m=n-2;
    else m=n-1;
    if(a==c and b==c)++m;

    if(m>d){
        cout << -1 << endl;
    }else{
        cout << n <<' '<< m<<endl;;
        if(b==c and a!=c){
            cout << 0 <<' '<< 1 <<endl;
            FOR(i,2,2+c-1){
                cout << 1 << ' '<<i<<endl;
            }
            FOR(i,c+1,n){
                cout << 0 << ' '<<i <<endl;
            }
        }
        if(b==c and a==c){
            cout << 0 << ' '<<1 <<endl;
            cout << 1 << ' '<<0 <<endl;
            FOR(i,2,2+c-2){
                cout << 0 << ' '<<i << endl;
            }
        }
        if(b!=c and a!=c){
            REP(i,a-c-1){
                cout << 0 <<' '<< i+2 <<endl;
            }
            REPN(i,a-c+1,b-c-1){
                cout << 1 <<' '<< i <<endl;
            }
            if(c != 0){
                cout << 0 <<' '<< a+b-c*2<<endl;
                cout << 1 <<' '<< a+b-c*2<<endl;
                REPN(i,a+b-c*2,c-1){
                    cout << i << ' '<<i+1 << endl;
                }
            }
        }
        if(b!=c and a== c){
            cout <<1<< ' '<<0 <<endl;
            FOR(i,2,2+c-1){
                cout << 0 <<' '<< i<<endl;
            }
            FOR(i,c+1,n){
                cout << 1 <<' '<< i <<endl;
            }

        }
    }





    return 0;
}
