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
struct Factorial{
    int n;
    vector<long long> fac,inv,bell;
    Factorial(long long n):n(n),fac(n+1),inv(n+1),bell(0,1){
        fac[0]=1;
        for(int i=0; i<n; ++i)fac[i+1]=fac[i]*(i+1)%MOD;
        inv[n]=modpow(fac[n],MOD-2);
        for(int i=n-1; i>=0; --i)inv[i]=inv[i+1]*(i+1)%MOD;
    };
    long long modpow(long long a, long long n,long long mod=MOD){
        long long i=1,ret=1,p=a;
        while(i<=n){if(i&n){ret=(ret*p)%mod;}i=(i<<1);p=(p*p)%mod;}
        return ret;
    }
    long long comb(int a, int b){return (fac[a]*inv[b]%MOD)*inv[a-b]%MOD;}
    void calc_bell(int a, int b){
        assert(a<=b);
        bell.resize(b);
        bell[0]=1;
        for(int i=a; i<b; ++i){
            for(int j=0; j<i; ++j){
                bell[i]+=bell[j]*comb(i-1,j);
                bell[i]%=MOD;
            }
        }
    }
    long long get_bell(int i){
        if((int)bell.size()<=i)calc_bell((int)bell.size(),i+1);
        return bell[i];
    }
};
struct Problem{
    int m,n;
    vector<vector<int>> t;
    UnionFind uf;
    Factorial f;
    Problem(LL m,LL n):m(m),n(n),t (n,vector<int>(m)),uf(m),f(2000){};

    void solve(){
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                char tmp;
                cin >> tmp;
                t[i][j]=tmp-'0';
            }
        }
        for(int i=0; i<m; ++i){
            for(int j=i+1; j<m; ++j){
                bool ok = true;
                for(int k=0; k<n; ++k){
                    if(t[k][i]!=t[k][j])ok=false;
                }
                if(ok)uf.unite(i,j);
            }
        }
        LL ans=1;
        for(int i=0; i<m; ++i){
            if(uf.is_par(i)){
                ans=(ans*f.get_bell(uf.size(i)))%MOD;
            }
        }
        cout << ans << "\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long m=0,n;
    cin >> m >> n;
    Problem p(m,n);
    p.solve();
    return 0;
}

