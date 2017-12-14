#include <bits/stdc++.h>
using namespace std;

#define DBG(...)
using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;


struct UnionFind{
    vector<int> par;
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
    bool is_root(int x){return root(x)==x;}
    bool is_same(int x,int y){return root(x) == root(y);}
    int size(int x){return -par[root(x)];}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    UnionFind uf(1000);

    return 0;
}