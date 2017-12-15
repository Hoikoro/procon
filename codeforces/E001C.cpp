#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n,ans;
    vector<pair<double,int> > angle;
    cin >>n;
    REP(i,n){
        double tmp1,tmp2;
        cin >> tmp1>>tmp2;
        angle.pb(make_pair(atan2(tmp2,tmp1)+acos(-1.0),i+1));
    }
    // REP(i,n) cout << angle[i].first <<' '<< angle[i].second <<endl;
    sort(angle.begin(),angle.end());
    angle.pb(make_pair(angle[0].first+acos(-1.0)*2,angle[0].second));
    //REP(i,n+1) cout << angle[i].first <<' '<< angle[i].second <<endl;
    double mini =7.0;
    ans=1;
    REP(i,n){
        ans=(mini >(angle[i+1].first-angle[i].first) ? i : ans);
        mini=min(mini,angle[i+1].first-angle[i].first);
    }
	cout << angle[ans].second << ' ' << angle[ans+1].second << endl;
	return 0;
}
