#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

typedef pair<int,int> pii;
struct Edge{
    int from,to;
    LL cost;
    Edge(int from,int to)
        : from(from),to(to) {};
};
typedef vector<vector<Edge>> Graph;

/*int anc(int now,int s,vector<vector<int>> &par){
    REP(i,18){
        if((s>>i)%2==1) now=par[i][now];
    }
    return now;
}*/

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,mdep=0;
    cin >> n;
    Graph T(n);
    vector<vector<int>> d(n);
    vector<int>par(n);
    REP(i,n) par[i]=-1;
    vector<int>dep(n);

    REP(i,n-1){
        int a,b;
        cin >> a >>b;
        a--;b--;
        T[a].PB(Edge(a,b));
        T[b].PB(Edge(b,a));
    }
    queue<int> Q;
    Q.push(0);
    par[0]=0;
    d[0].PB(0);
    while(!Q.empty()){
        int nx=Q.front();
        Q.pop();
        for(auto x: T[nx]){
            if(par[x.to]==-1){
                par[x.to]=x.from;
                Q.push(x.to);
                dep[x.to]=dep[x.from]+1;
                mdep=max(mdep,dep[x.to]);
                d[dep[x.to]].PB(x.to);
            }
        }
    }

    vector<int>l(n),u(n),ans(n);
    REP(i,n){
        l[i]=-INF;
        u[i]=INF;
    }
    int k,ev;
    cin >>k;
    REP(i,k){
        int a,b;
        cin >> a>>b;
        l[--a]=b;
        u[a]=b;
        if(i==0) ev=(dep[a]+b)%2;
        else if(ev!=(dep[a]+b)%2){
            cout << "No" <<endl;
            return 0;
        }
    }
    for(int i=mdep; i>0;--i){
        for(auto x : d[i]){
            if(l[x]>u[x]){
                cout << "No" <<endl;
                return 0;
            }
            l[par[x]]=max(l[par[x]],l[x]-1);
            u[par[x]]=min(u[par[x]],u[x]+1);
        }
    }
    if(l[0]>u[0]){
        cout << "No" <<endl;
        return 0;
    }else{
        queue<int> R;
        R.push(0);
        ans[0]=u[0];
        while(!R.empty()){
            int nx=R.front();
            R.pop();
            for(auto x: T[nx]){
                if(x.to!=par[x.from]){
                    ans[x.to]=min(ans[x.from]+1,u[x.to]);
                    R.push(x.to);
                }
            }
        }
    }
    cout <<"Yes"<<endl;
    REP(i,n)cout<< ans[i]<</*' ' <<u[i] <<' '<<l[i] <<*/endl;

    return 0;
}
