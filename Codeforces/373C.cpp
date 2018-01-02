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
    int n,t,f[200020]={},l=300000;
    string s,ans;
    cin >> n >> t>>s;
    int d=s.find('.');
    //OUT(d)
    //int upp=stoi(s.substr(0,d));
    //OUT(upp)
    for(int i=n-1;i>d;--i){
        if(s.at(i)>'4'){
            f[i]=1;
        }
        if(s.at(i)=='4'&&f[i+1]>0){
            f[i]=f[i+1]+1;
        }
    }
    //REP(i,n) OUT(f[i])
    FOR(i,d+1,n){
        if(f[i]<=t && f[i] >0){
            ans=s.substr(0,i);
            l=i;
            if(ans.at(i-1)=='.'){
                ans=ans.substr(0,i-1);
                l=i-1;
            }
            break;
        }
    }
    if(l==300000){
        cout << s << endl;
        return 0;
    }
    //OUT(ans)
    while(1){
        if(ans.at(l-1)!='9'){
            ans.at(l-1)++;
            break;
        }else{
            ans.at(l-1)='0';
            if(l==1){
                ans='1'+ans;
                break;
            }
            --l;
        }
    }
    cout<< ans << endl;
    return 0;
}
