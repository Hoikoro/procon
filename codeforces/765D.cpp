#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dbgsplit(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dbgsplit(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}
using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

struct UnionFind{
    vector<int> par; //par: -1*elements(root) number of par(not root)
    UnionFind(int n){
        par = vector<int>(n,-1);
    }
    int root(int x){
        return par[x]<0?x:(par[x]=root(par[x]));
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

void no(){cout << -1 <<"\n"; exit(0);}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> f(n+1),parents(1),id(n+1);
    UnionFind uf(n+1);
    for(int i=1; i<=n; ++i){
        cin >> f[i];
    }
    for(int i=1; i<=n; ++i){
        if(f[f[i]]!=f[i])no();
        uf.unite(i,f[i]);
    }
    for(int i=1; i<=n; ++i){
        if(uf.par[i]<0)parents.push_back(i);
        id[i]=parents.size()-1;
    }

    cout << parents.size()-1<<"\n";
    for(int i=1; i<=n; ++i){
        cout << id[uf.root(i)];
        if(i==n)cout <<"\n";
        else cout << ' ';
    }

    for(int i=1; i<(int)parents.size(); ++i){
        cout << parents[i];
        if(i==(int)parents.size()-1)cout <<"\n";
        else cout << ' ';
    }

    return 0;
}

