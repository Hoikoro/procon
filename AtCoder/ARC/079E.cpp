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
    vector<LL> a,sub,m;
    Problem(LL n):n(n),a(n),sub(n),m(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        LL sum=0;
        for(int i=1; i<n; ++i){
            sub[i]=(a[i]-a[0])/(n+1);
            sum+=sub[i];
        }
        DBG(sum)
        for(int i=0; i<n; ++i){
            a[i]=a[i]+sum-sub[i]*(n+1);
        }
        DBG(a)
        if(*max_element(a.begin(),a.end())<n){
            cout << sum<<"\n";
            return;
        }
        sort(a.begin(),a.end());
        for(int i=0; i<n; ++i){
            for(int j=0; j<n-1; ++j){
                a[j]++;
            }
            a[n-1]-=n;
            sort(a.begin(),a.end());
            m[(i+1)%n]=a[n-1];
        }
        DBG(m)
        for(int i=0; i<n; ++i){
            m[i]=max(0ll,(m[i]-n+1))*n+(LL)i;
        }
        m[0]+=n;
        DBG(m)
        cout << sum+*min_element(m.begin(),m.end()) <<"\n";
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

