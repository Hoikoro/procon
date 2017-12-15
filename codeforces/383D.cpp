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

struct UnionFind{
    vector<int> par; //par: -1*elements(root) number of par(not root)
    UnionFind(int n){
        par = vector<int>(n,-1);
    }
    int root(int x){
        if(par[x]<0){
            return x;
        }else{
            return par[x]=root(par[x]);
        }
    }
    void unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            par[y] += par[x];
            par[x] = y;
        }
        return;
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    int size(int x){
        return -par[root(x)];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,sumw;
    cin >> n >> m >> sumw;
    vector<int> w(n),b(n);
    vector<pair<int,int>> g(n);//<w,b>
    vector<vector<int>> u(n);
    UnionFind uf(n);
    REP(i,n)cin >> w[i];
    REP(i,n)cin >> b[i];
    REP(i,m){
        int tm,tmp;
        cin >> tm >> tmp;
        uf.unite(--tm,--tmp);
    }
    REP(i,n){
        u[uf.root(i)].push_back(i);
    }
    REP(i,n){
        for(int x: u[i]){
            g[i].FI+=w[x];
            g[i].SE+=b[x];
        }
    }

    int dp[1010]={},ddp[1010]={};
    int lock[1010]={};
    fill(lock,lock+1010,-1);

    for(int i=0;i<n;i++){
        if(g[i].FI!=0){
            for(int j=sumw;j>=g[i].FI;--j){
                if(dp[j]<dp[j-g[i].FI]+g[i].SE){
                    lock[j]=i;
                    dp[j]=dp[j-g[i].FI]+g[i].SE;
                }
            }
        }
    //REP(i,12)cout<<i<<' '<< lock[i]<<' '<<dp[i]<<endl;

        for(int x: u[i]){
            //cout << x << endl;
            for(int j=sumw;j>=w[x];--j){
                if(lock[j-w[x]]==i){
                    if(dp[j]<ddp[j-w[x]]+b[x]){
                        dp[j]=ddp[j-w[x]]+b[x];
                    }
                    continue;
                }else if(dp[j]<dp[j-w[x]]+b[x]){
                    dp[j]=dp[j-w[x]]+b[x];
                    lock[j]=i;
                }
            }
    //REP(i,12)cout<<i<<' '<< lock[i]<<' '<<dp[i]<<endl;
        }
    FOR(i,0,sumw+1)ddp[i]=dp[i];

    }
    int ret=0;
    FOR(i,0,sumw+1)ret=max(ret,dp[i]);
    cout << ret<<endl;

    return 0;
}
