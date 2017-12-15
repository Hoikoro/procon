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

LL t;
struct UnionFind{
    vector<int> par;
    vector<LL> w;
    UnionFind(int n){
        par = vector<int>(n,-1);
        w=vector<LL>(n,0);
    }
    int root(int x){
        if(par[x]<0){
            return x;
        }else{
            return par[x]=root(par[x]);
        }
    }
    void unite(int x,int y, LL a){
        x=root(x);
        y=root(y);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            par[y] += par[x];
            par[x] = y;
        }
        w[y]=w[y]+w[x]+a;
        return;
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    int size(int x){
        return -par[root(x)];
    }
    LL rest(int x){
        return max(0ll,t-w[root(x)]);
    }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    LL e;
    cin >> n >> e >> t;
    LL ans=e;
    vector<LL> x(n),dx(n-1);
    REP(i,n) cin >> x[i];
    REP(i,n-1) dx[i]=(x[i+1]-x[i])*2;
    UnionFind P(n);
    typedef tuple<LL,int,int> TP;//cost,l,r
    priority_queue<TP> Q;
    REP(i,n-1){
        Q.push(make_tuple(min(t,2*t-dx[i]),i,i+1));
    }
    while(!Q.empty() && get<0>(Q.top())>0){
        LL c,l,r;
        tie(c,l,r)=Q.top();
        cerr<< c << ' ' << l << ' ' << r << endl;
        Q.pop();
            //cout << c << ' ' << l << ' ' <<r <<endl;

        if((l==0 && r==n-1) || (l==0 && !P.same(r,r+1)) || (r==n-1 && !P.same(l-1,l)) || (!P.same(l-1,l) && !P.same(r,r+1))){
            //cout << c << ' ' << l << ' ' <<r <<endl;
            P.unite(l,r,dx[l+P.size(l)-1]);
            //cout <<P.w[P.root(l)]<<endl;
            if(r!=n-1){
                int newr=r+P.size(r+1);
                LL r1=P.rest(l),r2=P.rest(newr);
                Q.push(make_tuple(min(t,r1+r2-dx[r]),l,newr));
            }
            if(l!=0){
                int newl=l-P.size(l-1);
                LL r1=P.rest(r),r2=P.rest(newl);
                Q.push(make_tuple(min(t,r1+r2-dx[l-1]),newl,r));
            }
        }
    }

    REP(i,n){
        if(P.par[i]<0)ans+=max(t,P.w[i]);
    }
    cout << ans <<endl;
    return 0;
}
