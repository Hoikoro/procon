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
    vector <int> a,used;
    set<int> s;
    Problem(LL n):n(n),a(n),used(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
            a[i]--;
            if(a[i]==i)a[i]=1;
            else {
                a[i]=0;
                s.insert(i);
            }
        }
        s.insert(n);
        int ans =0;
        for(int i=0; i<n;++i){
            if(a[i]==0)continue;
            int lb = *s.lower_bound(i);
            int dist = lb-i;
            if(dist%2==0){
                ans += dist/2;
            }else{
                //if(i>0 and used[i-1]==0){
                    ans+=(dist+1)/2;
                //}else{
                    //ans+=(dist+1)/2;
                    //used[lb]=1;
                //}
            }
            i=lb;
        }

        cout <<ans <<"\n";
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

