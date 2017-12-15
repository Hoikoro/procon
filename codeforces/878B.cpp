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
    LL n,k,m;
    vector<deque<pair<int,int>>> q;
    Problem():q (32){};

    void solve(){
        cin >> n >> k >> m;
        for(int i=0; i<n; ++i){
            int tmp; cin >> tmp;
            if(i==0)q[0].push_back({tmp,1});
            else{
                if(tmp==q[0].back().first) q[0].back().second++;
                else q[0].push_back({tmp,1});
            }
        }
        int len=0;
        for(int i=0; i<(int)q[0].size(); ++i){
            q[0][i].second%=k;
            len+=q[0][i].second;
        }
        if(q[0][0].first!=q[0].back().first){
            cout << len*m <<"\n";
            return;
        }
        if((int)q[0].size()==1){
            cout << (len*m)%k <<"\n";
            return;
        }

        int a = (int)q[0].size();
        if((q[0][0].second+q[0][a-1].second)%k!=0){
            cout << (len*m-(q[0][0].second+q[0][a-1].second)/k*k*(n-1)) <<"\n";
            return;
        }
        for(int i=(int)q[0].size()-2; i>=0; --i){
            if(q[0][i].first!=q[0][a-1-i].first)
            if(q[0][i].second+q[0][a-1-i].second)
        }


    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    Problem p;
    p.solve();
    return 0;
}

