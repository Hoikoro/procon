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
    vector<LL> r,g,b;
    Problem(LL n):n(n){};

    void solve(){
        LL ans =0;
        for(int i=0; i<n; ++i){
            LL p;
            char c;
            cin >> p >> c;
            if(c=='G')g.push_back(p);
            if(c=='B')b.push_back(p);
            if(c=='R')r.push_back(p);
        }
        if(g.empty()){
            if(!b.empty())ans += b.back()-b[0];
            if(!r.empty())ans += r.back()-r[0];
        }else{
            if(!b.empty())ans += g[0]-min(g[0],b[0]);
            if(!r.empty())ans += g[0]-min(g[0],r[0]);
            for(int i=0; i<(int)g.size()-1; ++i){
                vector<LL> bb;
                bb.push_back(g[i]);
                for(auto it = upper_bound(b.begin(),b.end(),g[i]);it<b.end() and *it<g[i+1];++it){
                    bb.push_back(*it);
                }
                bb.push_back(g[i+1]);
                vector<LL> rr;
                rr.push_back(g[i]);
                for(auto it = upper_bound(r.begin(),r.end(),g[i]);it<r.end() and *it<g[i+1];++it){
                    rr.push_back(*it);
                }
                rr.push_back(g[i+1]);
                ans +=min(2*(g[i+1]-g[i]),3*(g[i+1]-g[i])-maxdiff(bb)-maxdiff(rr));
            }
            if(!b.empty())ans += max(g.back(),b.back())-g.back();
            if(!r.empty())ans += max(g.back(),r.back())-g.back();
        }
        cout << ans << "\n";
    }
    LL maxdiff(vector<LL> &v){
        LL ret = 0;
        for(int i=0; i<(int)v.size()-1; ++i){
            ret=max(ret,v[i+1]-v[i]);
        }
        return ret;
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

