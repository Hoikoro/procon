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

int n,m,tmp,t[220000],r[220000],tr[220000],dr;

int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    scanf("%d %d", &n,&m);
    vector<int> a;
    vector<int> b (n);
    REP(i,n){
        scanf("%d",&tmp);
        a.push_back(tmp);
    }

    REP(i,m){
        scanf("%d %d",&t[i],&r[i]);
        tr[r[i]]=i+1;
    }
    for(int i=n;i>=1;--i){
        tr[i]=max(tr[i+1],tr[i]);
        //OUT(tr[i]);
    }
    int k=n;
        while(tr[k]==0){
            b[k-1]=a[k-1];
            a.pop_back();
            --k;
        }
        sort(a.begin(),a.end());
        vector<int>::iterator g=a.end()-1,h=a.begin();
    for(int i=k;i>=1;--i){
        if(tr[i]!=tr[i+1]){
            dr=t[tr[i]-1];
        }
        //OUT(dr)
        if(dr==1){
            b[i-1]=*g;
            g--;
        }else{
            b[i-1]=*h;
            h++;
        }
    }
    REP(i,n-1){
        printf("%d ",b[i]);
    }
    printf("%d\n", b[n-1]);
    return 0;
}
