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
    vector<vector<int> > par(110000);
    int memo[110000]={};

int dfs(int a, int d){
    int ret=-1;
    memo[a]=1;
    if(par[a].empty()) return d;
    while(!par[a].empty()){
        int tmp=*par[a].begin();
        par[a].erase(par[a].begin());
        ret=max(ret,dfs(tmp,d+1));
    }
    return ret;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n;
    vector<pair<int, int> > bcn;
    cin >>n;
    REP(i,n){
        int tm,tmp;
        cin>>tm>>tmp;
        bcn.pb(make_pair(tm,tmp));
    }
    sort(bcn.begin(),bcn.end());
    REP(i,n){
        int tmp;
        tmp=lower_bound(bcn.begin(),bcn.end(),make_pair(bcn[i].first-bcn[i].second,0))-bcn.begin();
        par[tmp].pb(i+1);
    }

	cout << n-dfs(0,0) << endl;
	return 0;
}
