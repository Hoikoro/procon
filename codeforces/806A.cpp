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
    LL a,b,c,d;
    LL Solve(){
        if((a!=0 and c==0) or (a<b and c==d)){
            return -1;
        }
        LL lb=0, ub=b+10;
        while(ub-lb>1){
            LL mid= (lb+ub)/2;
            //DBG(mid,check(mid))
            if(check(mid))ub=mid;
            else lb=mid;
        }
        //DBG(ub)
        return ub*d-b;
    }
    bool check(LL k){
        return (k*d>=b)and (k*c>=a and (k*c-a)<=(k*d-b));
    }
    void solve(){
        cin >> a >> b >> c >> d;
        cout << Solve() <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long t=0;
    cin >> t;
    for(int i=0; i<t; ++i){
        Problem p;
        p.solve();
    }

    return 0;
}

