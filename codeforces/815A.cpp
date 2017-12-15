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

struct Problem{
    int n,m;
    vector<vector<int>> g;
    vector<int> r,c;
    Problem(LL n, LL m):n(n),m(m),g (n,vector<int>(m)),r(n),c(m){};
    void fail() {cout << -1 <<"\n"; exit(0);}
    void solve(){
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin >> g[i][j];
            }
        }
        for(int j=1; j<m; ++j){
            c[j]=g[0][j]-g[0][0];
        }
        for(int i=1; i<n; ++i){
            for(int j=1; j<m; ++j){
                if(c[j]!=g[i][j]-g[i][0]) fail();
            }
        }
        for(int i=1; i<n; ++i){
            r[i]=g[i][0]-g[0][0];
        }
        for(int i=1; i<n; ++i){
            for(int j=1; j<m; ++j){
                if(r[i]!=g[i][j]-g[0][j])fail();
            }
        }
        int diff=g[0][0]-r[0]-c[0];
        for(int i=0; i<n; ++i){
            r[i]+=diff;
        }
        if(*min_element(c.begin(),c.end())+ *min_element(r.begin(),r.end())<0)fail();
        if(m<n){
            int tmp=*min_element(r.begin(),r.end());
            for(int i=0; i<n; ++i){
                r[i]-=tmp;
            }
            for(int j=0; j<m; ++j){
                c[j]+=tmp;
            }
        }else{
            int tmp=*min_element(c.begin(),c.end());
            for(int i=0; i<n; ++i){
                r[i]+=tmp;
            }
            for(int j=0; j<m; ++j){
                c[j]-=tmp;
            }
        }

        cout << accumulate(r.begin(),r.end(),0)+accumulate(c.begin(),c.end(),0)<<"\n";
        for(int i=0; i<n; ++i){
            for(int j=0; j<r[i]; ++j){
                cout << "row "<<i+1<<"\n";
            }
        }
        for(int i=0; i<m; ++i){
            for(int j=0; j<c[i]; ++j){
                cout << "col "<<i+1<<"\n";
            }
        }

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

