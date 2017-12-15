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
    char ans[13][2]={};
    int a,b,dif;
    bool f=false;
    string s; cin >> s;
    REP(i,27){
        FOR(j,i+1,27){
            if(s[i]==s[j] && j-i!=1){
                a=i; b=j; dif=(b-a-1)/2; f=true;
            }
        }
    }
    //cout << a <<' '<<b<<endl;
    if(f){
        rotate(s.begin(),s.begin()+a,s.end());
        //OUT(s)
        for(int i=dif;i>=0;--i){
            ans[i][0]=s[dif-i];
        }
        int tmp=0;
        REPN(i,1,14){
            if(dif+i==b-a) continue;
            ans[tmp][1]=s[dif+i];
            tmp++;
        }
        tmp=0;
        FOR(i,dif+1+14,27){
            ans[12-tmp][0]=s[i];
            tmp++;
        }
        REP(i,13) cout << ans[i][0];
        cout<< endl;
        REP(i,13) cout << ans[i][1];
        cout << endl;
    }else{
        cout << "Impossible" <<endl;
    }



    return 0;
}
