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
    vector<LL> a,b,c;
    Problem(LL n):n(n),a(n),b(n),c(n){};
    LL maxi(vector<LL> &v){
        LL m=0, s=0;
        for(int i=0; i<(int)v.size(); ++i){
            s+=v[i];
            if(s<0){
                s=0;
            }
            if(m<s){
                m=s;
            }
        }
        return m;
    }

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
            if(i>0 and i%2==1){
                LL tmp=abs(a[i]-a[i-1]);
                b[i]=tmp;
                c[i]=-tmp;
            }else if (i>0){
                LL tmp=abs(a[i]-a[i-1]);
                b[i]=-tmp;
                c[i]=tmp;

            }
        }
        DBG(b,c)
        cout << max(maxi(b),maxi(c)) <<"\n";

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

