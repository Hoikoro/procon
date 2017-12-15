#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>
#include <numeric>
using namespace std;

typedef long long LL; typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int n,m,fa[110000],x,y,dir[110000],vis[110000];
vector<vector<int>> v,son;
void ancestor(int a){
    if(fa[a]==0){
        vis[a]=1;
        return;
    }
    if (!(vis[fa[a]]==1)){
        ancestor(fa[a]);
        v[a].insert(v[a].end(),v[fa[a]].begin(),v[fa[a]].end());
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
    }
    vis[a]=1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    v = vector<vector<int>>(100100, vector<int>(100100));
    son = vector<vector<int>>(100100, vector<int>(100100));
    scanf("%d %d",&n,&m);
    REP(i,m){
        scanf("%d %d",&x,&y);
        son[x].push_back(y);
    }
    REPN(i,1,n){
        scanf("%d",&x);
        dir[i]=x;
        v[i].push_back(i);
    }
    REPN(i,1,n){
        ancestor(i);
    }



    return 0;
}
