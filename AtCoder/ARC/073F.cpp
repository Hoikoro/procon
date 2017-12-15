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
struct state{
    LL s,a;
    state(LL s,LL a): s(s),a(a){};

};
struct comp{
    bool operator() (state &a ,state &b){
        return a.s <b.s;
    }
};

struct Problem{
    LL n,q,a,b;
    vector<LL> x;
    vector<state> v;
    Problem(LL n, LL q):n(n),q(q),x(q){};

    void solve(){
        cin >> a >> b;
        for(int i=0; i<q; ++i){
            cin >> x[i];
        }
        v.emplace_back(abs(x[0]-a),b);
        v.emplace_back(abs(x[0]-b),a);
        if(q==1){
            cout << min(abs(a-x[0]),abs(b-x[0])) <<"\n";;
            return;
        }
        for(int i=1; i<q; ++i){
            vector<state> tmp;
            for(auto &j: v){
                tmp.emplace_back(j.s+abs(x[i]-x[i-1]),j.a);
                tmp.emplace_back(j.s+abs(x[i]-j.a),x[i-1]);
            }
            v.clear();
            sort(tmp.begin(),tmp.end(),comp());
            unordered_map<LL,LL> um;
            for(auto &j: tmp){
                if(abs(j.a-tmp[0].a)>=j.s-tmp[0].s and(um.find(j.a)==um.end() or um[j.a]>j.s)){
                    v.push_back(j);
                    um[j.a]=j.s;
                }
            }
            DBG(i,tmp[0].s,tmp.size())
            if(i==q-1)cout << tmp[0].s <<"\n";
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,q;
    cin >> n >> q;
    Problem p(n,q);
    p.solve();
    return 0;
}

