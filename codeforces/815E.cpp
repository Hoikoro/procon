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
    Problem(LL n):n(n){};

    void solve(){

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    multimap<int,int> m;
    DBG(m)
    m.emplace(1,10);
    m.emplace(1,12);
    m.emplace(10,101);
    DBG(m)
    m.erase(1);
    DBG(m)
    deque<int> d={1,1,1,1,1};
    DBG(d)
    multiset<int> s;
    DBG(s)
    s.insert(10);
    s.insert(10);
    DBG(s)
    vector<pair<tuple<char,int,int>,string>> a={{{'c',1,22},"hello"}};
    DBG(a)
    Problem p(n);
    p.solve();
    return 0;
}

