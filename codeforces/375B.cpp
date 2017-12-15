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
    int n,ans[2]={},tmp=0;
    bool w=false,p=false;
    string s;
    cin >>n >> s;
    REP(i,n){
        if(s[i]!='(' and s[i] !=')' and s[i]!='_'){
            if(p and !w) ans[1]++;
            if(!p) tmp++;
            w=true;
        }else{
            ans[0]=max(ans[0],tmp);
            tmp=0;
            w=false;
            if(s[i]=='('){
                p=true;
            }else if(s[i]==')'){
                p=false;
            }
        }
    }
    ans[0]=max(ans[0],tmp);

    cout << ans[0] << ' ' << ans[1] <<endl;


    return 0;
}
