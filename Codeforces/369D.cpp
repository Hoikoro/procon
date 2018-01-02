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
#define MOD 1000000007


int n,vis[200020]={},to[200020]={};

int  dfs(int i,int d) {
    if (vis[i]!=0) return d+1-vis[i];
    vis[i]=d+1;
    return dfs(to[i],d+1);
}
long long pow_(long long a, long long n){
    if(n==0) return 1;
    long long re=pow_(a*a,n/2);
    if(n%2==1) re= re*a;
    return re;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REPN(i,1,n){
        cin >> to[i];
    }
    LL ans=1;
    REPN(i,1,n){
        int tmp=dfs(i,0);
        if(tmp>0){
            ans=ans*(pow_(2,tmp)-2)%MOD;
        }
    }
    cout << ans <<endl;
    return 0;
}
