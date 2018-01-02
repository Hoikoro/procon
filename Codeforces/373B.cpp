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
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,b[2]={},r[2]={},ans,tmp;
    string s;
    cin >> n >> s;
    ans=n;
    REP(i,n){
        if(s.at(i)=='b'){
            b[i%2]++;
        }
        if(s.at(i)=='r'){
            r[i%2]++;
        }
    }

    //rbrb...
    int rb=0,rr=(n-1)/2+1,bb=n/2;
    tmp=min(min(b[0],bb-b[1]),min(r[1],rr-r[0]));
    rb+=tmp;
    b[1]+=tmp,r[0]+=tmp,r[1]-=tmp,b[0]-=tmp;
    rb+=b[0]+r[1];

    ans=min(ans,rb);
    //OUT(rb)
    b[0]=b[1]=r[0]=r[1]=0;
    REP(i,n){
        if(s.at(i)=='b'){
            b[i%2]++;
        }
        if(s.at(i)=='r'){
            r[i%2]++;
        }
    }


    int br=0;
    bb=(n-1)/2+1,rr=n/2;
    tmp=min(min(b[1],bb-b[0]),min(r[0],rr-r[1]));
    br+=tmp;
    b[0]+=tmp,r[1]+=tmp,r[0]-=tmp,b[1]-=tmp;
    br+=b[1]+r[0];

    ans=min(br,ans);

//OUT(br)
    OUT(ans)




    return 0;
}
