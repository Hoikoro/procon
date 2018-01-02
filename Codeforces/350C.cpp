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

int n,a[220000],m,b[220000],c[220000],ans[3]={0,-1,-1};
map<int,int> sci; // lan,cnt

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i,n){
        int a;
        cin >>a;
        if(sci.count(a)==0){
            sci[a]=1;
        }else{
            sci[a]++;
        }
    }
    cin>>m;
    REPN(i,1,m){
        cin >> b[i];
    }
    REPN(i,1,m){
        cin >> c[i];
    }

    REPN(i,1,m){
        if(sci[b[i]]>ans[1] or (sci[b[i]]==ans[1] and sci[c[i]]>ans[2]) ){
            ans[0]=i;
            ans[1]=sci[b[i]];
            ans[2]=sci[c[i]];
        }

    }


    cout << ans[0] << endl;



    return 0;
}
