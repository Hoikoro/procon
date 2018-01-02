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
#define dump(a) cout<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;
double eps=1e-13;
double solve(int a, int b, double t){
    double l=0.1,u=5.8;
    while(u-l>5e-10){
        double m=(l+u)/2.0;
        if(pow(m,(double)a)*pow(log(m),(double)b)<t-eps){
            l=m;
        }else{
            u=m;
        }
    }
    return (l+u)/2.0;
}

int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    cout << fixed << setprecision(11);
    double pre[11][11][1002];
    FOR(i,1,11)FOR(j,1,11)FOR(k,10,1002){
        pre[i][j][k]=solve(i,j,0.01*k);
    }
    int m,a,b,pt;
    cin >> m;
    double t,l,u,mid,tmp,tmp2;
    REP(i,m){
        scanf("%d %d %lf",&a,&b,&t);
        pt=floor((t+0.00005)*100);
        l=pre[a][b][pt],u=pre[a][b][pt+1];
        //l=0.1;u=22222.0;
        if(a==0){
            printf("%.11lf\n",exp(pow(t,1.0/b)));
            continue;
        }
        if(b==0){
            printf("%.11lf\n",pow(t,1.0/a));
            continue;
        }
        while(u-l>16e-10){
            mid=(l+u)/2.0;
            if(a==b)tmp=pow(mid*log(mid),b);
            else tmp=pow(mid,a)*pow(log(mid),b);
            if(tmp<t-eps){
                l=mid;
            }else{
                u=mid;
            }
        }
        printf("%.11lf\n",(l+u)/2.0);
    }

    return 0;
}
