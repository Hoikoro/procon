#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <queue>
#include <list>
#include <set>

#define REP(i,n) for(int (i)=0; (i)<(n) ;(i)++)
#define REPP(i,n) for(int (i)=1; (i)<=(n) ;(i)++)
#define pb push_back

using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    string a,b;
    long long int a1[220000]={},a0[220000]={},ans=0;
    cin >>a >>b;
    a1[0]=a.at(0)-'0';
    a0[0]=1-a1[0];
    REPP(i,a.size()-1){
        a1[i]=a1[i-1]+a.at(i)-'0';
        a0[i]=i+1-a1[i];
    }
    for(int i=a.size();i<b.size();i++){
        a1[i]=a1[i-1];
        a0[i]=a0[i-1];
    }
    for(int i=b.size()-1;i>=b.size()-a.size()+1;i--){
        a1[i]-=a1[i-(b.size()-a.size()+1)];
        a0[i]-=a0[i-(b.size()-a.size()+1)];
    }
    REP(i,b.size()){
        if(b.at(i)=='0'){
            ans+=a1[i];
        }else{
            ans+=a0[i];
        }
    }
        cout <<ans <<endl;

/*REP(i,b.size()){
	cout << b.at(i)<<a0[i]<< a1[i]<<endl;
}*/
	return 0;
}
