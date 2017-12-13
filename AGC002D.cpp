#include <bits/stdc++.h>
using namespace std;

#define DBG(...) ;
using LL = long long;

struct UnionFind{
    vector<pair<int,int>> memo;
    vector<int> par;
    UnionFind(int n){
        par = vector<int>(n,-1);
    }
    int root(int x){
        if(par[x]<0)return x;
        return root(par[x]);
    }
    void unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            par[y] += par[x];
            par[x] = y;
        }
    }
    void reversible_unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            memo.emplace_back(x,par[x]);
            memo.emplace_back(y,par[y]);
            par[y] += par[x];
            par[x] = y;
        }
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    int size(int x){
        return -par[root(x)];
    }
    int query(int x, int y){
        int px=root(x),py=root(y);
        if(px==py)return -par[px];
        else return -par[px]-par[py];
    }
    void revert(){
        for(int i=memo.size()-1; i>=0; --i){
            par[memo[i].first]=memo[i].second;
        }
        memo.clear();
    }
};

struct Problem{
    int n,m,q;
    vector<pair<int,int>> edges;
    vector<UnionFind> uf_trees;
    Problem(int n, int m):n(n),m(m),edges(m+1){};

    void solve(){
        int interval=((int)sqrt(m)+1);
        UnionFind uf(n);
        uf_trees.push_back(uf);
        for(int i=1; i<=m; ++i){
            int a,b;
            cin >> a >> b;
            uf.unite(--a,--b);
            edges[i]={a,b};
            if(i%interval==0) uf_trees.push_back(uf);
        }

        cin >> q;
        for(int i=0; i<q; ++i){
            int x,y,z;
            cin >> x >> y >> z;
            --x;--y;
            int lb=0,ub=m/interval+1;
            while(ub-lb>1){
                int med=(lb+ub+1)/2;
                if(uf_trees[med].query(x,y)>=z) ub=med;
                else lb=med;
            }
            int add =0;
            while(uf_trees[lb].query(x,y)<z){
                ++add;
                uf_trees[lb].reversible_unite(edges[lb*interval+add].first,edges[lb*interval+add].second);
            }
            uf_trees[lb].revert();
            cout << lb*interval+add <<"\n";
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}