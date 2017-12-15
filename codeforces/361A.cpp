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

bool zero,sn;
int l=2,r=0,u=2,d=0,n,t;
char tmp;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    REP(i,n){
        cin >>tmp;
        t=tmp-'0';
        if(t==0) zero=true;
        else{
            l=min(l,(t-1)%3);
            r=max(r,(t-1)%3);
            u=min(u,(t-1)/3);
            d=max(d,(t-1)/3);
            if(t==7 || t==9) sn=true;
        }
    }


    if(zero){
        if(u==0){
            cout << "YES" <<endl;
        }else{
            cout << "NO" <<endl;
        }

    }else{
        if((r-l)==2 && (d-u)==2 && sn==true){
            cout << "YES" << endl;
        }else{
            cout << "NO" <<endl;
        }
    }


    return 0;
}
