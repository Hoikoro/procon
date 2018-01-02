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

int ans;
int n,m,n2,m2,a;
vector<int> nn,mm;

int pow_(int a, int n){
    if(n==0) return 1;
    int re=pow_(a*a,n/2);
    if(n%2==1) re= re*a;
    return re;
}

int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    scanf("%d %d",&n,&m);
    n--;m--;
    n2=n;m2=m;
    if(n==0){
        nn.push_back(0);
    }
    if(m==0){
        mm.push_back(0);
    }
    while(n>0){
        nn.push_back(n%7);
        n/=7;
    }
    while(m>0){
        mm.push_back(m%7);
        m/=7;
    }
    //OUT(nn.size());
    int dis=nn.size()+mm.size();
    if(dis>7){
        ans=0;
        printf("%d\n",ans);
        return 0;
    }

    REP(i,pow_(7,dis)){
        vector<int> aa; /*(nn.size());*/
        a=i;
        REP(j,dis){
            aa.push_back(a%7);
            a/=7;
        }
        int an=i/pow_(7,mm.size());
        int am=i%pow_(7,mm.size());

        sort(aa.begin(),aa.end());
        aa.erase(unique(aa.begin(),aa.end()),aa.end());
        if(aa.size()!=dis){
            continue;
        }

        if(an<=n2&&am<=m2){
            ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}
