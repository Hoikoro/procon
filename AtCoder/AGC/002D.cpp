#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dreplace(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...) ;
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dreplace(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
template<typename T> using V = vector<T>;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;
struct UnionFind{
    vector<pair<int,int>> memo;
    vector<int> par; //par: -1*elements(root) number of par(not root)
    UnionFind(int n){
        par = vector<int>(n,-1);
    }
    int root(int x, bool rec=false){
        if(par[x]<0)return x;
        if(par[par[x]]<0) return par[x];
        if(rec)memo.emplace_back(x,par[x]);
        return par[x]=root(par[x]);
    }
    int stableroot(int x){
        if(par[x]<0)return x;
        return stableroot(par[x]);
    }
    void unite(int x,int y,bool rec=false){
        x=root(x,rec);
        y=root(y,rec);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            par[y] += par[x];
            par[x] = y;
        }
        return;
    }
    void stableunite(int x,int y){
        x=stableroot(x);
        y=stableroot(y);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            memo.emplace_back(x,par[x]);
            memo.emplace_back(y,par[y]);
            par[y] += par[x];
            par[x] = y;
        }
        return;
    }
    bool same(int x,int y,bool rec=false){
        return root(x,rec) == root(y,rec);
    }
    int size(int x,bool rec=false){
        return -par[root(x,rec)];
    }
    int query(int x, int y){
        int px=stableroot(x),py=stableroot(y);
        if(px==py){return -par[px];}
        else {return -par[px]-par[py];}
    }
    void revert(){
        for(int i=memo.size()-1; i>=0; --i){
            par[memo[i].first]=memo[i].second;
        }
        memo.clear();
        memo.shrink_to_fit();
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m,interval;
    cin >> n>>m;
    interval=(int)(sqrt(m)+1);
    vector<UnionFind> sduf;
    UnionFind uf(n);
    vector<int> aa(m+1),bb(m+1);
    sduf.push_back(uf);
    for(int i=1; i<=m; ++i){
        int a,b;
        cin >> a >> b;
        uf.unite(--a,--b);
        aa[i]=a;bb[i]=b;
        if(i%interval==0){sduf.push_back(uf);}
    }
    int q; cin >> q;
    for(int i=0; i<q; ++i){
        int x,y,z,div=0,p=0;
        cin >> x >> y >> z;
        --x;--y;
        int lb=0,ub=m/interval+1;
        while(ub-lb>1){
            int med=(lb+ub+1)/2;
            if(sduf[med].query(x,y)>=z) ub=med;
            else lb=med;
        }
        div=lb;
        while(sduf[div].query(x,y)<z){
            sduf[div].stableunite(aa[div*interval+p+1],bb[div*interval+p+1]);
            ++p;
        }
        sduf[div].revert();

        cout << div*interval+p <<"\n";
    }

    return 0;
}

