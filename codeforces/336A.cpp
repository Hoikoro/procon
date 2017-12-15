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
    int a,b,n,ans=0;
    cin>>n>>ans;
    REP(i,n){
        cin >>a >>b;
        ans=max(a+b,ans);
    }


	cout << ans << endl;
	return 0;
}
