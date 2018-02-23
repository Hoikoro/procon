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
    int n,k;
    vector<vector<int>> bb_,ww_;
    Problem(LL n, LL k):n(n),k(k),bb_ (4*k+2,vector<int>(4*k+2)),ww_ (4*k+2,vector<int>(4*k+2)){};

    void solve(){
        int b=0,w=0;
        auto bb = [&](int x, int y) -> auto& {return bb_[x+1][y+1];};
        auto ww = [&](int x, int y) -> auto& {return ww_[x+1][y+1];};
        for(int i=0; i<n; ++i){
            int x,y;
            char c;
            cin >> x >> y >> c;
            x%=(2*k);y%=(2*k);
            if(c=='B'){
                bb(x,y)+=1;
                bb((x+2*k)%(4*k),(y)%(4*k))+=1;
                bb((x)%(4*k),(y+2*k)%(4*k))+=1;
                bb((x+2*k)%(4*k),(y+2*k)%(4*k))+=1;
                b++;
            }else{
                ww(x,y)+=1;
                ww((x+2*k)%(4*k),(y)%(4*k))+=1;
                ww((x)%(4*k),(y+2*k)%(4*k))+=1;
                ww((x+2*k)%(4*k),(y+2*k)%(4*k))+=1;
                w++;
            }
        }
        for(int i=0; i<2*k+2; ++i){
            DBG(bb_[i],ww_[i])
        }
        for(int i=1; i<4*k; ++i){
            for(int j=0; j<4*k; ++j){
                bb(i,j)+=bb(i-1,j);
                ww(i,j)+=ww(i-1,j);
            }
        }
        for(int i=0; i<4*k; ++i){
            for(int j=1; j<4*k; ++j){
                bb(i,j)+=bb(i,j-1);
                ww(i,j)+=ww(i,j-1);
            }
        }
        DBG(n)
        for(int i=0; i<2*k+2; ++i){
            DBG(bb_[i],ww_[i])
        }
        int ans = -INF;
        for(int i=0; i<k; ++i){
            for(int j=0; j<2*k; ++j){
                int cb=bb(i+k-1,j+k-1)-bb(i-1,j+k-1)-bb(i+k-1,j-1)+bb(i-1,j-1);
                cb+=bb(i+2*k-1,j+2*k-1)-bb(i+k-1,j+2*k-1)-bb(i+2*k-1,j+k-1)+bb(i+k-1,j+k-1);
                int cw=ww(i+k-1,j+k-1)-ww(i-1,j+k-1)-ww(i+k-1,j-1)+ww(i-1,j-1);
                cw+=ww(i+2*k-1,j+2*k-1)-ww(i+k-1,j+2*k-1)-ww(i+2*k-1,j+k-1)+ww(i+k-1,j+k-1);
                int tmp = cw+(b-cb);
                DBG(i,j,cb,cw,tmp)
                ans =max(ans,tmp);
            }
        }
        cout << ans <<"\n";
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0,k;
    std::cin >> n >> k;
    Solver::Problem p(n,k);
    p.solve();
    return 0;
}

