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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m,num[100010],pos[100010]={1},x[100010],y[100010];
    fill(num,num+100010,1);
    cin >> n >> m;
    REP(i,m){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    REP(i,m){
        --num[x[i]];
        ++num[y[i]];
        if(pos[x[i]]>0){
            pos[y[i]]=1;
        }
        if(num[x[i]]==0){
            pos[x[i]]=0;
        }
    }

    cout << accumulate(pos,pos+n,0)<<endl;

    return 0;
}
