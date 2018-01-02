#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef vector<LL> VLL;

#define REP(i,n) for(int (i)=0; (i)<(n) ;(i)++)
#define REPP(i,n) for(int (i)=1; (i)<=(n) ;(i)++)
#define ALL(s) (s).begin(), (s).end()
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int n,par[550000],dep[550000],visited[550000]={0,1},ans;
vector<vector<int>> edge(550000),d(550000);
void search(int a){
    for(auto x:edge[a]){
        if(visited[x]==1) continue;
        visited[x]=1;
        par[x]=par[a];
        dep[x]=dep[a]+1;
        if(edge[x].size()==1){
            d[par[x]].push_back(dep[x]);
            continue;
        }
        search(x);
    }
}

int main(){
	//cin.tie(0);
	//ios::sync_with_stdio(false);
    scanf("%d",&n);
    REP(i,n-1){
        int tmp1,tmp2;
        scanf("%d %d",&tmp1,&tmp2);
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }
    for(auto x : edge[1]){
        par[x]=x;
        dep[x]=1;
        visited[x]=1;
        if(edge[x].size()==1){
            d[x].push_back(1);
        }else{
            search(x);
        }
        sort(ALL(d[x]));
        for(auto y=d[x].begin()+1;y<d[x].end();y++){
            *y=max(*y,*(y-1)+1);
        }
        ans=max(ans,d[x].back());
    }

    cout << ans <<endl;
	return 0;
}
