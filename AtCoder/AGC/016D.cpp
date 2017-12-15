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
    vector<int> a,b;
    set<pair<int,int>> st;
    vector<vector<int>> g;
    vector<int> vis;
    Problem(LL n):n(n),a(n),b(n){};

    void solve(){
        int xa=0,xb=0;
        for(int i=0; i<n; ++i){
            cin >> a[i];
            xa^=a[i];
        }
        for(int i=0; i<n; ++i){
            cin >> b[i];
            xb^=b[i];
        }
        vector<int> a2(a),b2(b);
        a2.push_back(xa);
        b2.push_back(xb);
        sort(a2.begin(),a2.end());
        sort(b2.begin(),b2.end());
        if(a2!=b2){
            cout << -1 <<endl;
            return;
        }
        a2.erase(unique(a2.begin(),a2.end()),a2.end());
        b2.erase(unique(b2.begin(),b2.end()),b2.end());

        a.push_back(xa);
        b.push_back(xb);
        for(int i=0; i<a.size(); ++i){
            a[i]=lower_bound(a2.begin(),a2.end(),a[i])-a2.begin();
            b[i]=lower_bound(b2.begin(),b2.end(),b[i])-b2.begin();
        }
        g.resize((int)a2.size());
        vis.resize((int)a2.size());
        int ans=0;
        for(int i=0; i<n; ++i){
            DBG(a[i],b[i])
            if(a[i]!=b[i]){
                ans++;
                st.insert({b[i],a[i]});
                g[b[i]].push_back(a[i]);
            }
        }
        int now=a.back();
        DBG(g,st)
        DBG(now)
        while(1){
            DBG(now,st)
            dfs(now);
            if(st.size()==0)break;
            ans++;
            now=st.begin()->first;
        }
        cout << ans <<"\n";
    }
    void dfs(int s){
        vis[s]=1;
        for(int x:g[s]){
            st.erase({s,x});
            if(!vis[x])dfs(x);
        }
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

