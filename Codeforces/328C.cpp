#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    long long t,w,b,g,gg,ans,in;
    bool o=false;
    in=7e18;
    cin >> t >> w >> b;
    g=__gcd(w,b);
    gg=w/g*b;
    //cout << in << endl;
    if((double)w/g*b>(double)in) {
        ans=min(t,min(w,b)-1);
    }
    else if (gg>t){
        ans=min(t,min(w,b)-1);
    }
    else {
        ans=t/gg*min(w,b);
        ans+=min(t%gg,min(w,b)-1);
    }
	long long answ=ans/__gcd(ans,t);
    t/=__gcd(ans,t);
    cout << answ << '/' << t << endl;
	return 0;
}
