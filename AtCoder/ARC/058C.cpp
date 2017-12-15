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
#include <numeric>
using namespace std;

typedef long long LL; typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

vector<int> d;

bool chk(int a){
    while(a>0){
        int tmp=a%10;
        a/=10;
        if(find(d.begin(),d.end(),tmp)!=d.end()){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,ans;
    cin >> n >> k;
    REP(i,k){
        int t;
        cin >> t;
        d.push_back(t);
    }

    while(1){
        if(chk(n)==true){
            ans=n;
            break;
        }
        n++;
    }

    cout << ans <<endl;

    return 0;
}
