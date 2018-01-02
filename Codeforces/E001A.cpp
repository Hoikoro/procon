#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
long long pow_(long long a, long long n){
    if(n==0) return 1;
    long long re=pow_(a*a,n/2);
    if(n%2==1) re= re*a;
    return re;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int t,lg;
    long long n,ans;
    cin >> t;
    REP(i,t){
        cin >> n;
        ans=n*(n+1)/2;
        lg=(long long )log2(n);
        ans-=2*(pow(2,lg+1)-1);
        cout << ans << endl;
    }
    
	//cout <<  << endl;
	return 0;
}
