#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n,a[4][2]={},ans;

    cin >> n;
    if(n==1) {
        cout << -1 << endl;
        return 0;
    }
    REP(i,n){
        cin >> a[i][0] >> a[i][1];
    }
    if(n==2){
        if(a[1][0]==a[0][0] || a[1][1]==a[0][1]){
            cout << -1 << endl;
            return 0;
        }else{
            ans=abs((a[1][0]-a[0][0])*(a[1][1]-a[0][1]));
        }
    }
    if(n>2){
        int x1,x2,y1=0,y2=0;
        x1=a[0][0];
        y1=a[0][1];
        for(int i=1;i<n;i++){
            if(a[i][0]!=x1) x2=a[i][0];
            if(a[i][1]!=y1) y2=a[i][1];
        }
        ans=abs((x1-x2)*(y1-y2));
    }
    
    cout << ans << endl;
	return 0;
}
