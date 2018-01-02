#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    vector <pair<long long int, long long int> > y;
    long long int n,k,b,l,r;
    bool ans=true;

    cin >>n;
    cin >>l>> r;
    REP(i,n){
        cin >>k>>b;
        y.pb(make_pair(k*l+b,k*r+b));
    }
    sort(y.begin(),y.end());
    for(int i=0;i<n-1;i++){
        if(y[i].second>y[i+1].second) ans = false;
    }
    if(ans==true) cout << "NO" << endl;
    else cout << "YES" << endl;
	return 0;
}
