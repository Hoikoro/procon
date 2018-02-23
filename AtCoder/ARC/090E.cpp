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
#define int LL
struct Problem{
    struct Edge{
        int from,to;
        LL cost;
        Edge(int from,int to,LL cost)
            : from(from),to(to),cost(cost) {};
    };
    typedef vector<vector<Edge>> Graph;
    typedef pair<LL,int> pii;

        LL dijkstra(const int start, const vector<vector<Edge>> &graph , vector<pii> &prev){
        int visited =0,N=graph.size();
        LL thres=LINF;
        //vector<char> visited(N,false);
        // <<cost , place>, prev>
        priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>> > Q;
        Q.push(make_pair(make_pair(0,start),-1));
        while(!Q.empty()){
            LL cost; int place,from;
            cost=Q.top().first.first; place = Q.top().first.second; from=Q.top().second;
            DBG(Q.top())
            Q.pop();
            if(cost>thres)return 1;
            if((prev[place].second==-1 or cost == prev[place].second) and from!=-1){
                h[from].push_back(Edge(from,place,cost-prev[from].second));
                rh[place].push_back(Edge(place,from,cost-prev[from].second));
                DBG(from,place)
            }
            if(prev[place].second!=-1) continue;
            prev[place]={from,cost};
            visited++;
            if(visited==N) {
                thres = cost;
                //return 1;
            }
            for(int j=0;j<(int)graph[place].size();j++){
                Q.push(make_pair(make_pair(graph[place][j].cost+cost,graph[place][j].to),place));
            }
        }
        return -1;
    }
    int n,m,s,t;
    LL dist;
    Graph g,h,rh;
    vector<pii> pre;
    map<pair<int,int>,LL> mp,mp2;
    Problem(LL n):n(n),g(n),h(n),rh(n),pre(n,{0,-1}){};

    void solve(){
        cin >> m >> s >>t;
        --s;--t;
        for(int i=0; i<m; ++i){
            int u,v,d;
            cin >> u >> v >> d;
            --u;--v;
            g[u].push_back(Edge(u,v,d));
            g[v].push_back(Edge(v,u,d));
        }
        dijkstra(s,g,pre);
        dist = pre[t].second;
        DBG(dist)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        vector<LL> dp(n),visit1(n),visit2(n);
        dp[s]=1;
        DBG(n)
        while(!pq.empty()){
            auto now_ = pq.top();
            int now=now_.second;
            pq.pop();
            DBG(now)
            if(pre[now].second*2==dist){
                mp[{now,now}]=dp[now];
            }
            for(auto &&x:h[now]){
                DBG(now,x.to)
                dp[x.to]+=dp[now];
                dp[x.to]%=MOD;
                if(visit1[x.to]==0)pq.push({pre[x.to].second,x.to});
                visit1[x.to]=1;
                if(pre[now].second*2<dist and pre[x.to].second*2>dist){
                    mp[{now,x.to}]=dp[now];
                }
            }
        }
        DBG(mp)

        priority_queue<pair<int,int>> ps;
        ps.push({dist,t});
        vector<LL> dp2(n);
        dp2[t]=1;
        while(!ps.empty()){
            auto now_ = ps.top();
            int now = now_.second;
            DBG(now)
            ps.pop();
            if(pre[now].second*2==dist){
                mp2[{now,now}]=dp2[now];
            }
            for(auto &&x:rh[now]){
                DBG(now,x.to)
                dp2[x.to]+=dp2[now];
                dp2[x.to]%=MOD;
                if(visit2[x.to]==0)ps.push({pre[x.to].second,x.to});
                visit2[x.to]=1;
                if(pre[now].second*2>dist and pre[x.to].second*2<dist){
                    mp2[{now,x.to}]=dp2[now];
                }
            }
        }
        DBG(mp2)
        LL ans =dp2[s]*dp2[s]%MOD;
        DBG(ans)
        for(auto &&x:mp2){
            pair<int,int> y ={x.first.second,x.first.first};
            ans -= (x.second*mp[y])%MOD*x.second%MOD*mp[y]%MOD;
            ans%=MOD;
            ans+=MOD;
            ans%=MOD;
        }
        cout << ans <<"\n";
    }
};
}
#undef int
int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long n=0;
    std::cin >> n;
    Solver::Problem p(n);
    p.solve();
    return 0;
}

