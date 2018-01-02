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
    string s[1010];
    int n;
    bool ans= false;
    cin >> n;
    REP(i,n){
        cin >> s[i];
    }
    REP(i,n){
        if(s[i][0]=='O' && s[i][1]=='O'){
            ans=true;
            s[i][0]='+';
            s[i][1]='+';
            break;
        }else if(s[i][3]=='O' && s[i][4]=='O'){
            ans=true;
            s[i][3]='+';
            s[i][4]='+';
            break;
        }
    }
    if(ans){
        cout << "YES" << endl;
        REP(i,n){
            cout <<s[i] <<endl;
        }
    }else{
        cout << "NO" <<endl;
    }

    return 0;
}
