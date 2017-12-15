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
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;
void fail(){cout << "NO"<<endl;exit(0);}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s,t[4]={"dream","dreamer","erase","eraser"};
    cin >>s;
    int p=0,l=s.size();
    while(p<l){
        if(s[p]=='d'){
            if(s.substr(p,5)!=t[0])fail();
            if(s[p+5]!='e'){
                p=p+5;
                continue;
            }else if(p==l-7 and s.substr(p,7)=="dreamer"){
                cout << "YES"<<endl;
                return 0;
            }else if(s.substr(p+5,3)=="ere"  or s.substr(p+5,3)=="erd"){
                p=p+7;
                continue;
            }else if(s.substr(p+5,3)=="era"){
                p=p+5;
                continue;
            }else{
                fail();
            }
        }else if(s[p]=='e'){
            if(s.substr(p,5)!=t[2])fail();
            if(s[p+5]=='r'){
                p=p+6;
            }else if(s[p+5]!='e' or s[p+5]!='d'){
                p=p+5;
                continue;
            }else{
                fail();
            }
        }else{
            fail();
        }
    }
    cout << "YES"<<endl;



    return 0;
}
