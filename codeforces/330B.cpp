#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define MOD 1000000007


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
    long long int n,k,a[101000]={},b[101000]={},ans=1;
    cin >> n >> k;
    REP(i,n/k){
        cin >>a[i];
    }
    REP(i,n/k){
        cin >> b[i];
    }

    REP(i,n/k){
        long long an=0;
        an=(pow_(10,k)-1)/a[i]+1-((b[i]+1)*pow_(10,k-1)-1)/a[i]-1+(b[i]*pow_(10,k-1)-1)/a[i]+1;
        if(b[i]==0&&a[i]>1) an--;
        ans=(ans*an)%MOD;
        //cout << an << endl;
    }
	cout << ans << endl;
	return 0;
}
