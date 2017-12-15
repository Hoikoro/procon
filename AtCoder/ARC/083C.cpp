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
    LL a,b,c,d,e,f;
    void solve(){
        cin >> a >>b >> c >> d >> e >> f;
        vector<int> s(3001),w(31);
        s[0]=1;
        w[0]=1;
        for(int i=1; i<=3000; ++i){
            if((i-c>=0 and s[i-c]>0)or(i-d>=0 and s[i-d]>0))s[i]=1;
        }
        for(int i=1; i<=30; ++i){
            if((i-a>=0 and w[i-a]>0)or(i-b>=0 and w[i-b]>0))w[i]=1;
        }
        pair<LL,LL> ans={100*a,0};
        for(int i=0; i<=3000; ++i){
            for(int j=0; j<=30; ++j){
                if(s[i]>0 and w[j]>0 and i+j*100<=f and j*e>=i and ans.first*i>ans.second*j*100) ans={100*j,i};
            }
        }
        cout << ans.first+ans.second << ' ' << ans.second<<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Problem p;
    p.solve();
    return 0;
}

