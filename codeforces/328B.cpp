#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    long long n,ans;
    cin >> n;
    ans=(n-3)*(n-1)+1;
    
	cout << ans << endl;
	return 0;
}
