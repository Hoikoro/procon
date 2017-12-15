#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n;
    long long int b[220000]={},ans=0;
    cin >> n;
    REP(i,n){
        cin>>b[i+1];
        ans+=abs(b[i+1]-b[i]);
    }
    
	cout << ans << endl;
	return 0;
}
