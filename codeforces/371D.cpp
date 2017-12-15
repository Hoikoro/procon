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
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    bool solvex=false,solvey=false;
    int c[2][4]={},n,q=0,ans[202];
    scanf("%d",&n);
    int b[4]={1,n,1,n};
    REP(i,40){
        printf("? 1 1 %d %d\n",(b[0]+b[1])/2,n);
        fflush(stdout);
        scanf("%d", &ans[q]);
        q++;
        printf("? 1 1 %d %d\n", (b[2]+b[3])/2,n);
        fflush(stdout);
        scanf("%d", &ans[q]);
        q++;
        if(ans[q-2]==0){
            b[0]=(b[0]+b[1])/2;
        }else{
            b[1]=(b[0]+b[1])/2;
        }
        if(ans[q-1]<2){
            b[2]=(b[2]+b[3])/2;
        }else{
            b[3]=(b[2]+b[3])/2;
        }
    }
    c[0][2]=b[1];c[1][2]=b[3];

    b[0]=b[2]=1;b[1]=b[3]=n;q=0;
    REP(i,40){
        printf("? %d 1 %d %d\n",(b[0]+b[1])/2,n,n);
        fflush(stdout);
        scanf("%d", &ans[q]);
        q++;
        printf("? %d 1 %d %d\n", (b[2]+b[3])/2,n,n);
        fflush(stdout);
        scanf("%d", &ans[q]);
        q++;
        if(ans[q-2]==0){
            b[1]=(b[0]+b[1])/2;
        }else{
            b[0]=(b[0]+b[1])/2;
        }
        if(ans[q-1]<2){
            b[3]=(b[2]+b[3])/2;
        }else{
            b[2]=(b[2]+b[3])/2;
        }
    }
    c[0][0]=b[0];c[1][0]=b[2];

    b[0]=b[2]=1;b[1]=b[3]=n;q=0;
    REP(i,40){
        printf("? 1 1 %d %d\n",n,(b[0]+b[1])/2);
        fflush(stdout);
        scanf("%d", &ans[q]);
        q++;
        printf("? 1 1 %d %d\n", n,(b[2]+b[3])/2);
        fflush(stdout);
        scanf("%d", &ans[q]);
        q++;
        if(ans[q-2]==0){
            b[0]=(b[0]+b[1])/2;
        }else{
            b[1]=(b[0]+b[1])/2;
        }
        if(ans[q-1]<2){
            b[2]=(b[2]+b[3])/2;
        }else{
            b[3]=(b[2]+b[3])/2;
        }
    }
    c[0][3]=b[1];c[1][3]=b[3];

    b[0]=b[2]=1;b[1]=b[3]=n;q=0;
    REP(i,40){
        printf("? 1 %d %d %d\n",(b[0]+b[1])/2,n,n);
        fflush(stdout);
        scanf("%d", &ans[q]);
        q++;
        printf("? 1 %d %d %d\n", (b[2]+b[3])/2,n,n);
        fflush(stdout);
        scanf("%d", &ans[q]);
        q++;
        if(ans[q-2]==0){
            b[1]=(b[0]+b[1])/2;
        }else{
            b[0]=(b[0]+b[1])/2;
        }
        if(ans[q-1]<2){
            b[3]=(b[2]+b[3])/2;
        }else{
            b[2]=(b[2]+b[3])/2;
        }
    }
    c[0][1]=b[0];c[1][1]=b[2];

    vector<pair<pair<int,LL>,int>> rec;

    REP(i,16){
        printf("? %d %d %d %d\n", c[(i>>0)&1][0],c[(i>>1)&1][1],c[(i>>2)&1][2],c[(i>>3)&1][3]);
        fflush(stdout);
        int tmp;
        scanf("%d", &tmp);
        rec.push_back(make_pair(make_pair(tmp,(c[(i>>2)&1][2]-c[(i>>0)&1][0])*(c[(i>>3)&1][3]-c[(i>>1)&1][1])),i));
    }
    sort(rec.begin(),rec.end());
    int i=lower_bound(rec.begin(),rec.end(),make_pair(make_pair(1,0ll),0))->first.first;

    printf("! %d %d %d %d %d %d %d %d\n", c[(i>>0)&1][0],c[(i>>1)&1][1],c[(i>>2)&1][2],c[(i>>3)&1][3],c[!((i>>0)&1)][0],c[!((i>>1)&1)][1],c[!((i>>2)&1)][2],c[!((i>>3)&1)][3]);

    return 0;
}
