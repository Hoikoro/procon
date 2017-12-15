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
    int n,cnt;
    vector<vector<int>> t;
    vector<int> par,col;
    Problem(LL n):n(n),t(n),par(n),col(n,-1){};
    void dfs1(int p, int c){
        par[c]=p;
        for(auto x: t[c]){
            if(p!=x){
                dfs1(c,x);
            }
        }
    }
    void dfs2(int p, int c){
        cnt++;
        for(auto x: t[c]){
            if(p!=x and col[x]!=1){
                dfs2(c,x);
            }
        }
    }

    void solve(){
        for(int i=0; i<n-1; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            t[a].push_back(b);
            t[b].push_back(a);
        }
        col[0]=0;
        col[n-1]=1;
        dfs1(-1,0);
        deque<int> r;
        for(int i=par[n-1];i!=0;i=par[i]){
            r.push_back(i);
        }
        DBG(r)
        while(!r.empty()){
            col[r.back()]=0;
            r.pop_back();
            if(r.empty())break;
            col[r[0]]=1;
            r.pop_front();
            if(r.empty())break;
        }
        cnt=0;
        dfs2(-1,0);
        DBG(cnt)
        if(cnt>=n/2+1)cout << "Fennec" <<"\n";
        else cout << "Snuke" <<"\n";
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

