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
#include <random>
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
    Edge(int from,int to, LL cost)
        : from(from),to(to),cost(cost) {};
};
typedef vector<vector<Edge>> Graph;

int defineDepth(Graph &T, vector<int> &p, vector<int> &dep,vector<vector<int>> &dtov,int root){
    int ret =0;
    queue<int> Q;
    Q.push(root);
    p[root]=root;
    dtov[0].push_back(root);
    while(!Q.empty()){
        int nex=Q.front();
        Q.pop();
        for(auto &x: T[nex]){
            if(p[x.to]==-1){
                p[x.to]=x.from;
                Q.push(x.to);
                dep[x.to]=dep[x.from]+1;
                ret=max(ret,dep[x.to]);
                dtov[dep[x.to]].push_back(x.to);
            }
        }
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int>par(n,-1),dep(n),h(n);
    Graph T(n);
    vector<vector<int>> d(n);

    REP(i,n-1){
        int a,b;
        cin >> a >>b;
        a--;b--;
        T[a].PB(Edge(a,b,1));
        T[b].PB(Edge(b,a,1));
    }
    int r=0;
    REP(i,n){
        if(T[i].size()==1){
            r=i;
        }
    }
    int mdep=defineDepth(T,par,dep,d,r);
    vector<vector<LL>> dp(n,vector<LL>(44,0)),sum(n,vector<LL>(44,0));
    for(int i=mdep; i>=0;--i){
        for(auto x : d[i]){
            if(T[x].size()==1){
                dp[x][0]=1;
                dp[x][1]=1;
            }else{
                int hi=0;
                for(auto y: T[x]){
                    if(y.to!=par[x]){

                    }
                }
            }
        }
    }


    return 0;
}
