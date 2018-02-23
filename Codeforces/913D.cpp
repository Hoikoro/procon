#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;


namespace Solver{
#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif
using namespace std;
struct prob{
    int th;
    LL time;
    int id;
};
    bool comp(const prob &a, const prob &b){
        return a.th>b.th or (a.th==b.th and a.time<b.time);
    }
    bool comp2(const prob &a, const prob &b){
        return a.time<b.time;
    }
struct Problem{
    LL n,t;
    vector<prob> a;
    Problem(LL n):n(n),a(n){};
    bool ok(int x){
        auto it = lower_bound(a.begin(),a.end(),prob({x,LINF,0}),comp);
        vector<prob> v;
        copy(a.begin(),it,back_inserter(v));
        sort(v.begin(),v.end(),comp2);
        DBG(x)
        if(v.size()<x)return false;
        LL sum =0;
        for(int i=0; i<x ; ++i){
            sum+=v[i].time;
        }
        DBG(sum,t)
        return sum<=t;
    }
    vector<prob> check(int x){
        auto it = lower_bound(a.begin(),a.end(),prob({x,LINF,0}),comp);
        vector<prob> v;
        copy(a.begin(),it,back_inserter(v));
        sort(v.begin(),v.end(),comp2);
        return v;
    }
    void solve(){
        cin >> t;
        for(int i=0; i<n; ++i){
            int tmp,tmpt;
            cin >> tmp >> tmpt;
            a[i]={tmp,tmpt,i+1};
        }
        sort(a.begin(),a.end(),comp);
        LL ub = n+1,lb =0;
        while(ub-lb>1){
            LL mid = (ub+lb)/2;
            DBG(ub,lb,mid)
            if(ok(mid))lb=mid;
            else ub =mid;
        }
        cout << lb << "\n";
        auto ans = check(lb);
        cout << lb <<"\n";
        for(int i=0; i<lb; ++i){
            cout << ans[i].id <<' ';
        }

    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0;
    std::cin >> n;
    Solver::Problem p(n);
    p.solve();
    return 0;
}

