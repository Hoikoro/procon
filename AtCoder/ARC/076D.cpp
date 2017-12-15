#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

struct UnionFind{
    vector<int> par; //par: -1*elements(root) number of par(not root)
    UnionFind(int n){par = vector<int>(n,-1);}
    int root(int x){return par[x]<0?x:(par[x]=root(par[x]));}
    void unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            par[y] += par[x];
            par[x] = y;
        }
    }
    bool is_par(int x){return root(x)==x;}
    bool same(int x,int y){return root(x) == root(y);}
    int size(int x){return -par[root(x)];}
};

struct Problem{
    int n;
    vector<pair<int,int>> x,y;
    vector<tuple<int,int,int>> e;
    UnionFind uf;
    Problem(LL n):n(n),uf(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            int a,b;
            cin >> a >>b;
            x.emplace_back(a,i);
            y.emplace_back(b,i);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        for(int i=0; i<n-1; ++i){
            if(x[i].first==x[i+1].first){
                uf.unite(x[i].second,x[i+1].second);
            }else{
                e.emplace_back(x[i+1].first-x[i].first,x[i].second,x[i+1].second);
            }
            if(y[i].first==y[i+1].first){
                uf.unite(y[i].second,y[i+1].second);
            }else{
                e.emplace_back(y[i+1].first-y[i].first,y[i].second,y[i+1].second);
            }
        }
        sort(e.begin(),e.end());
        LL ans=0;
        for(int i=0;uf.size(0)<n;++i){
            int a,b,c;
            tie(a,b,c)=e[i];
            if(!uf.same(b,c)){
                uf.unite(b,c);
                ans+=a;
            }
        }
        cout << ans<<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

