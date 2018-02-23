#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;
#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif


namespace Solver{
using namespace std;

struct Problem{
    int n,k;
    Problem(LL n):n(n){};

    void solve(){
        string s,s_pre;
        k=1;
        while(k<n)k<<=1;
        k>>=1;
        DBG(k)
        cout << 0 <<endl;
        fflush(stdout);
        cin >> s_pre;
        if(s_pre=="Vacant")return;
        int now = k,prev=0;
        while(k>1){
            cout << now <<endl;
            fflush(stdout);
            cin >> s;
            k>>=1;
            if(s=="Vacant"){
                return;
            }else if(s!=s_pre){
                int tmp = now;
                now = (now+prev)/2;
                prev=tmp;
            }else{
                int tmp = now;
                if(prev<now){
                    while(now+k>=n)k>>=1;
                    now+=k;
                }else{
                    now-=k;
                }
                prev = tmp;
            }
            s_pre=s;
        }
        cout << now <<endl;
        fflush(stdout);
        cin >> s;
        assert(s=="Vacant");
    }
};
}

int main(){
    long long n=0;
    std::cin >> n;
    Solver::Problem p(n);
    p.solve();
    return 0;
}

