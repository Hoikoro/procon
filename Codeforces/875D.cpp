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
    LL n;
    vector<LL> a,reva,r,l;
    Problem(LL n):n(n),a(n),r(n),l(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        reva=a;
        reverse(reva.begin(),reva.end());
        stack<int> S;
        S.push(0);
        for(int i=1; i<n; ++i){
            if((a[S.top()]|a[i])==a[S.top()] and a[S.top()]!=a[i]) S.push(i);
            else{
                while(!S.empty() and (((a[S.top()]|a[i])!=a[S.top()]) or (a[S.top()] == a[i]))){
                    r[S.top()]=i;
                    S.pop();
                }
                S.push(i);
            }
        }
        while(!S.empty()){
            r[S.top()]=n;
            S.pop();
        }
        S.push(0);
        for(int i=1; i<n; ++i){
            if((reva[S.top()]|reva[i])==reva[S.top()]) S.push(i);
            else{
                while(!S.empty() and (reva[S.top()]|reva[i])!=reva[S.top()]){
                    l[S.top()]=i;
                    S.pop();
                }
                S.push(i);
            }
        }
        while(!S.empty()){
            l[S.top()]=n;
            S.pop();
        }
        reverse(l.begin(),l.end());
        for(int i=0; i<n; ++i){
            l[i]=(n-1)-l[i];
        }
        DBG(r)
        DBG(l)

        LL ans =0;
        for(int i=0; i<n; ++i){
            LL rd = r[i]-i;
            LL ld = i-l[i];
            ans+=(rd)*(ld)-1ll;
            DBG(ans)
        }
        cout << n*(n-1)/2-ans <<"\n";

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

