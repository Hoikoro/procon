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
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n)-1)
#define FOR(i,a,b) for(int (i)=(a); (i)<=(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int dep[100010],par[100010],n,k,ans;
priority_queue<pair<int,int>> d;
set<int> rem;
vector<set<int>> a(100010);
void dfs(int p){
    if(dep[p]<=k){
        rem.erase(p);
    }
    if(!a[p].empty()){
        for(auto&& x : a[p] ){
            dep[x]=dep[p]+1;
            rem.erase(x);
            if(dep[x]>k){
                d.push(make_pair(dep[x],x));
                rem.insert(x);
            }
            dfs(x);
        }
    }
    return;
}
void connectone(int b){
    a[par[b]].erase(b);
    par[b]=1;
    dep[b]=1;
    dfs(b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    REP(i,n){
        cin >> par[i+1];
        if(i+1>1){
            a[par[i+1]].insert(i+1);
        }
    }
    dfs(1);

    int ans=0;
    if(par[1]!=1){
        ++ans;
        par[1]=1;
    }
    while(!rem.empty()){
        int top=d.top().second;
        d.pop();
        //OUT(top)
        //OUT(dep[top])
        if(rem.find(top)!=rem.end()){
            REP(i,k-1){
                top=par[top];
            }
            connectone(top);
            //OUT(top)
            ++ans;
        }
    }
    cout << ans <<endl;




    return 0;
}
