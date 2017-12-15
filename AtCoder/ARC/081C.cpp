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
    int n;
    map<LL,LL> m;
    Problem(LL n):n(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            LL tmp;
            cin >>tmp;
            m[tmp]++;
        }
        LL a=0,b=0;
        auto it = m.end();
        for(it--;;it--){
            DBG(*it)
            if(it->second>=4){
                if(a==0)a=b=it->first;
                else b=it->first;
                break;
            }else if(it->second>=2){
                if(a==0)a=it->first;
                else{
                    b=it->first;
                    break;
                }
            }
            if(it==m.begin())break;
        }
        cout << a*b <<"\n";
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

