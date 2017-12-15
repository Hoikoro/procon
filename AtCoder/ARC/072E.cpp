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
    LL n,dist,query,lim;
    vector<LL> d,ans,mini,pos;
    Problem(LL n):n(n),d(n),ans(n),mini(n+1),pos(n+1){};

    void solve(){
        cin >> dist;
        lim=LINF;
        pos[0]=dist;
        for(int i=0; i<n; ++i){
            cin >> d[i];
        }
        for(LL i=0; i<n; ++i){
            dist=min(abs(dist-d[i]),dist);
            pos[i+1]=dist;
            if(pos[i+1]==0){
                lim=i;
                break;
            }
        }
        mini[n-1]=1;
        for(LL i=n-1; i>0; --i){
            if(d[i]<mini[i]*2)mini[i-1]=mini[i]+d[i];
            else mini[i-1]=mini[i];
        }
        cin >> query;
        for(LL i=0; i<query; ++i){
            LL tmp;
            cin >> tmp;
            tmp--;
            DBG(tmp,lim,mini[tmp],pos[tmp])
            cout << ((lim==LINF or(tmp<=lim and mini[tmp]<=pos[tmp]))?"YES":"NO") <<"\n";
        }

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

