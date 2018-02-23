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
struct UnionFind{
    vector<int> par; //par: -1*elements(root) number of par(not root)
    UnionFind(int n){par = vector<int>(n,-1);}
    int root(int x){return par[x]<0?x:(par[x]=root(par[x]));}
    void unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x!=y){
            if(par[x]<par[y]) swap(x,y);
            par[y] += par[x];
            par[x] = y;
        }
    }
    bool is_root(int x){return root(x)==x;}
    bool same(int x,int y){return root(x) == root(y);}
    int size(int x){return -par[root(x)];}
};
struct Problem{
    int n,m;
    vector<LL> a;
    LL ans;
    vector<vector<LL>> st,st2;
    UnionFind uf;
    Problem(LL n, LL m):n(n),m(m),a(n),ans(0),st(n),uf(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
            st[i].push_back(a[i]);
        }
        for(int i=0; i<m; ++i){
            int x,y;
            cin >> x >> y;
            uf.unite(x,y);
        }
        for(int i=0; i<n; ++i){
            int r = uf.root(i);
            if(r!=i){
                st[r].push_back(st[i][0]);
                st[i].pop_back();
            }
        }
        for(auto&&v: st){
            if(!v.empty())st2.push_back(v);
        }
        swap(st,st2);
        vector<priority_queue<LL,vector<LL>,greater<LL>>> Q((int)st.size());
        for(int i=0; i<(int)st.size(); ++i){
            for(int j=0; j<(int)st[i].size(); ++j){
                Q[i].push(st[i][j]);
            }
        }
        int cnt = 0;
        for(auto &&v: st){
            cnt+=((int)v.size()-2);
        }
        DBG(st)

        if((int)st.size()==1){
            cout << 0 <<"\n";
            return;
        }
        if(cnt<-2){
            cout << "Impossible"<<"\n";
            return;
        }
        int edge =0;
        for(auto &&s : Q){
            ans+=s.top();
            s.pop();
            edge++;
        }
        priority_queue<LL,vector<LL>,greater<LL>> pq;
        for(auto &&s :Q){
            while(!s.empty()){
                pq.push(s.top());
                s.pop();
            }
        }
        while(edge<(n-1-m)*2){
            ans+=pq.top();
            pq.pop();
            edge++;
        }
        cout << ans <<"\n";
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0,m;
    std::cin >> n >> m;
    Solver::Problem p(n,m);
    p.solve();
    return 0;
}

