#include <bits/stdc++.h>
using namespace std;
//unsolved
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
    LL n,q;
    vector<LL> qq,query;
    Problem(LL n, LL q):n(n),q(q),qq(q){};

    void solve(){
        if(q==0){
            for(int i=0; i<n; ++i){
                cout << 1 <<"\n";
            }
            return;
        }
        for(int i=0; i<q; ++i){
            cin >> qq[i];
        }
        query.push_back(qq.back());
        for(int i=(int)qq.size()-2; i>=0; --i){
            if(qq[i]<query.back())query.push_back(qq[i]);
        }
        if(query.back()>n)query.push_back(n);
        vector<LL> ans(query.back()+1),coeff((int)query.size());
        map<LL,LL> m;
        m[query[0]]=1;
        coeff[0]=1;
        for(int i=1; i<(int)query.size(); ++i){
            vector<LL> to_erase;
            LL add=0;
            for(auto it= m.lower_bound(query[i]); it!=m.end();++it){
                coeff[i]+=coeff[i-1]*(it->first/query[i]);
                add+=(it->first/query[i])*it->second;
                m[it->first%query[i]]+=it->second;
                to_erase.push_back(it->first);
            }
            for(auto x:to_erase)m.erase(x);
            m[query[i]]=add;
        }
        for(auto p : m){
            ans[p.first]+=p.second;
        }
        for(int i=(int)ans.size()-2; i>=1; --i){
            ans[i]+=ans[i+1];
        }
        for(int i=1; i<=n; ++i){
            if(i<(int)ans.size())cout << ans[i] <<"\n";
            else cout << 0 << "\n";
        }


    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,q;
    cin >> n>>q;
    Problem p(n,q);
    p.solve();
    return 0;
}

