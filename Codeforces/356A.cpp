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

int cnt[110],ans,mx;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i,5){
        int tmp;
        cin>>tmp;
        ans+=tmp;
        cnt[tmp]++;
    }
    FOR(i,1,101){
        if(cnt[i]>1){
            mx=max(mx,i*(min(cnt[i],3)));
        }
    }
    cout<<ans-mx<<endl;

    return 0;
}
