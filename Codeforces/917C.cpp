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
typedef vector<vector<long long >> Matrix;

struct Problem{
    LL x,k,n,q,g;
    vector<LL> c,sp,sp2;
    unordered_map<LL,LL> w;
    vector<vector<vector<LL>>> cost;
    Problem(LL x, LL k, LL n ,LL q):x(x),k(k),n(n),q(q),c(k+1),
    cost (28,vector<vector<LL>>((1<<k),vector<LL>((1<<k),LINF))){};

    vector<vector<LL>> calc(int x){
        vector<vector<LL>> ret((1<<k),vector<LL>((1<<k),LINF));
        for(int i=0; i<(1<<k); ++i){
            ret[i][i]=0;
        }
        for(int i=0; i<28; ++i){
            if((x&(1<<i))){
                auto tmp = ret;
                multiply(cost[i],tmp,ret);
            }
        }
        return ret;
    }
    void multiply(const Matrix &a, const Matrix &b, Matrix &ret){ //ret=a*b
        int k=a.size(),l=a[0].size(),m=b[0].size();
        //if(l!=b.size()) DBG("wrong size")

        for(int h=0;h<k;++h){
            if(h>0 and __builtin_popcount(h)!=x)continue;
            for(int i=0;i<m;++i){
                if(__builtin_popcount(i)!=x)continue;
                ret[h][i]=LINF;
                for(int j=0;j<l;j++){
                    ret[h][i]=min(ret[h][i],a[h][j]+b[j][i]);
                }
            }
        }
    }
    void solve(){
        g = n-x;
        for(int i=1; i<=k; ++i){
            cin >> c[i];
        }
        for(int i=0; i<q; ++i){
            LL a,b;
            cin >> a >> b;
            --a;
            sp.push_back(a);
            sp2.push_back(a-k);
            w[a]=b;
        }
        sp.push_back(g);
        sp2.push_back(g-k);
        sort(sp.begin(),sp.end());
        sort(sp2.begin(),sp2.end());

        for(int i=0; i<(1<<k); ++i){
            if(i%2 ==0)cost[0][i][i/2]=0;
            else{
                for(int j=1; j<=k; ++j){
                    if((i&(1<<j))==0){
                        int tmp = i-1+(1<<j);
                        tmp>>=1;
                        cost[0][i][tmp]=c[j];
                    }
                }
            }
        }
        for(int i=1; i<(int)cost.size(); ++i){
            multiply(cost[i-1],cost[i-1],cost[i]);
        }
        LL now = 0;
        vector<vector<LL>> ans (1,vector<LL>((1<<k),LINF));
        ans[0][(1<<x)-1]=0;
        while(now<g){
            LL nxt = *upper_bound(sp.begin(),sp.end(),now);
            if(nxt<=now+k){
                auto tmp = ans;
                fill(ans[0].begin(),ans[0].end(),LINF);
                for(int i=0; i<(1<<k); ++i){
                    if(i%2 ==0)ans[0][i/2]=min(ans[0][i/2],tmp[0][i]);
                    else{
                        for(int j=1; j<=k; ++j){
                            if((i&(1<<j))==0){
                                int tmp2 = i-1+(1<<j);
                                tmp2>>=1;
                                ans[0][tmp2]=min(ans[0][tmp2],tmp[0][i]+c[j]+w[now+j]);
                            }
                        }
                    }
                }
                now++;
            }else{
                nxt = *upper_bound(sp2.begin(),sp2.end(),now);
                auto tmp = ans;
                multiply(tmp,calc(nxt-now),ans);
                now=nxt;
            }
        }
        cout << ans[0][(1<<x)-1] << "\n";

    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long x,k,n,q;
    std::cin >> x >>k >> n >> q;
    Solver::Problem p(x,k,n,q);
    p.solve();
    return 0;
}

