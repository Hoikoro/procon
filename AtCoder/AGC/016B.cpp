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
    vector<int> a;
    Problem(LL n):n(n),a(n){};
    void no(){cout <<"No"<<"\n"; exit(0);}
    void yes(){cout <<"Yes"<<"\n"; exit(0);}
    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int diff=a[n-1]-a[0];
        if(diff>=2)no();
        if(diff==0){
            if(a[0]*2<=n or a[0]==n-1) yes();
            else no();
        }


        //diff=1, a[0]+1 types
        int s=upper_bound(a.begin(),a.end(),a[0])-a.begin();
        int l=n-s;
        DBG(l,s)
        if((a[0]+1-s)>0 and  2*(a[0]+1-s)<=l)yes();
        else no();
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

