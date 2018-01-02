#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <list>
#include <set>

#define REP(i,n) for(int (i)=0; (i)<(n) ;(i)++)
#define REPP(i,n) for(int (i)=1; (i)<=(n) ;(i)++)
#define pb push_back

using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n,a[110000],an=1,ans=0;
    cin>>n;
    REPP(i,n){
        int tmp;
        cin>>tmp;
        a[tmp]=i;
    }
    if(n==1){
        cout << '0' << endl;
        return 0;
    }
    REPP(i,n-1){
        if(a[i]<a[i+1]) an++;
        else an=1;
        ans=max(ans,an);
    }
	cout << n-ans << endl;
	return 0;
}
