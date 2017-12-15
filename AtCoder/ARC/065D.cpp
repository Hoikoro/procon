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
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;
struct UnionFind{
    vector<int> par; //par: -1*elements(root) number of par(not root)
    UnionFind(int n){
        par = vector<int>(n,-1);
    }
    inline int root(int x){
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
    inline bool same(int x,int y){
        return root(x) == root(y);
    }
    int size(int x){
        return -par[root(x)];
    }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,l;
    cin >> n >> k >> l;
    UnionFind road(n), rail(n);
    REP(i,k){
        int a,b;
        cin >> a >> b;
        road.unite(--a,--b);
    }
    REP(i,l){
        int a,b;
        cin >> a >> b;
        rail.unite(--a,--b);
    }
    map<PI,int> p;
    REP(i,n){
        p[{road.root(i),rail.root(i)}]++;
    }
    REP(i,n){
        cout<< p[{road.root(i),rail.root(i)}]<<(i!=n-1?" ":"\n");
    }
    return 0;
}
