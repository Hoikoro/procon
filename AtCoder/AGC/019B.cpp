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
    void solve(){
        string s;
        cin >> s;
        vector<char> c(2*(int)s.size()-1,'*');
        vector<int> res(2*(int)s.size()-1);
        for(int i=0; i<(int)s.size(); ++i){
            c[i*2]=s[i];
        }
        int i = 0, j = 0;
        while (i < c.size()) {
            while (i-j >= 0 && i+j < c.size() && c[i-j] == c[i+j]) ++j;
            res[i] = j;
            int k = 1;
            while (i-k >= 0 && i+k < c.size() && k+res[i-k] < j) res[i+k] = res[i-k], ++k;
            i += k; j -= k;
        }
        for(int i=0; i<res.size(); ++i){
            if(i%2==0)res[i]=(res[i]+1)/2;
            else res[i]/=2;
        }
        DBG(res)
        DBG(accumulate(res.begin(),res.end(),0))
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    Problem p;
    p.solve();
    return 0;
}

