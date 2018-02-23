#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;
#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif


namespace Solver{
using namespace std;

struct Problem{
    string s;
    int n;
    Problem(string s):s(s),n(s.length()){};

    void solve(){
        vector<int> cnt(n),sum,q;
        for(int i=0; i<n; ++i){
            if(s[i]=='(')cnt[i]=1;
            else if(s[i]==')')cnt[i]=-1;
            else {
                cnt[i]=-1;
                q.push_back(i);
            }
        }
        sum=cnt;
        for(int i=1; i<n; ++i){
            sum[i]+=sum[i-1];
        }
        int ans = 0;
        for(int i=0; i<n; ++i){
            int pos = lower_bound(q.begin(),q.end(),i)-q.begin();
            int tmp=0;
            for(int j=i; j<n; ++j){
                tmp+=cnt[j];
                if(tmp<0){
                    if(pos<(int)q.size() and q[pos]<=j){
                        tmp+=2;
                        pos++;
                    }else break;
                }
                if(tmp==0 and i<j){
                    ans++;
                }
            }
        }
        cout << ans <<"\n";
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    std::string n;
    std::cin >> n;
    Solver::Problem p(n);
    p.solve();
    return 0;
}

