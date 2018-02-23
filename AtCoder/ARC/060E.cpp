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
    int n,l,q;
    vector<vector<int>> lb;
    vector<int> x;
    Problem(LL n):n(n),lb (n,vector<int>(18)),x(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> x[i];
        }

        cin >> l >> q;
        for(int i=0; i<n; ++i){
            lb[i][0]=upper_bound(x.begin(),x.end(),x[i]+l)-x.begin()-1;
        }
        for(int i=1; i<18; ++i){
            for(int j=0; j<n; ++j){
                lb[j][i]=lb[lb[j][i-1]][i-1];
            }
        }
        for(int i=0; i<q; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            if(a>b)swap(a,b);
            int lb = 0,ub = b-a;
            while(ub-lb>1){
                int mid = (ub+lb)/2;
                if(check(a,b,mid)){
                    ub= mid;
                }else{
                    lb = mid;
                }
            }
            cout << ub <<"\n";
        }
    }
    bool check(int a, int b, int x){
        int now = a;
        for(int i=0; i<18; ++i){
            if((x>>i)&1){
                now=lb[now][i];
            }
        }
        return now>=b;
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

