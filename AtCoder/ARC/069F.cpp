#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dbgsplit(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dbgsplit(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}
using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

struct Edge{
    int from,to;
    Edge(int from,int to)
        : from(from),to(to){};
    Edge(){Edge(0,0);}
};
typedef vector<vector<Edge>> Graph;

struct stronglyConnectedComponents{
    vector<int> scrank,vis,po;
    Graph graph,rgraph;
    int size;
    stronglyConnectedComponents(int n){
        size=1;
        while(size<n)size*=2;
        scrank=vector<int>(size*4); vis=vector<int>(size*4);
        graph=Graph(size*4); rgraph=Graph(size*4);
    }
    private:
    void dfs(int a,Graph &g){
        vis[a]=1;
        for(int i=0; i<g[a].size(); ++i){
            if(!vis[g[a][i].to]) dfs(g[a][i].to,g);
        }
        po.push_back(a);
    }
    void rdfs(int a, int k, Graph &rg){
        scrank[a]=k;
        vis[a]=1;
        for(int i=0; i<rg[a].size(); ++i){
            if(!vis[rg[a][i].to]) rdfs(rg[a][i].to,k,rg);
        }
    }
    public:
    void calc(){
        for(int i=0; i<graph.size(); ++i){
            if(!vis[i]) dfs(i,graph);
        }
        fill(vis.begin(),vis.end(),0);
        int c=0;
        for(int i=rgraph.size()-1; i>=0; --i){
            if(!vis[po[i]]) rdfs(po[i],c++,rgraph);
        }
    }
    inline void add_edge(int a, int b){
        graph[a].emplace_back(a,b);
        rgraph[b].emplace_back(b,a);
    }
    void init(vector<LL> &id){
        for(int i=1; i<size; ++i){
            add_edge(2*i,i);
            add_edge(2*i+1,i);
            add_edge(i+2*size,2*i+2*size);
            add_edge(i+2*size,2*i+1+2*size);
        }
        for(int i=0; i<(int)id.size(); ++i){
            DBG(size,id[i],id[i^1])
            add_edge(id[i]+size,id[i^1]+3*size);
            add_edge(id[i]+3*size,id[i^1]+size);
        }
    }
    void build(vector<pair<LL,LL>> &c, LL d){
        for(int i=0; i<(int)c.size(); ++i){
            int ll=lower_bound(c.begin(),c.end(),make_pair(c[i].first-d+1,0ll))-c.begin();
            int rr=lower_bound(c.begin(),c.end(),make_pair(c[i].first+d,0ll))-c.begin();
            ll+=size; int lr=i+size;
            rr+=size; int rl=i+1+size;
            for(;ll<lr;ll>>=1,lr>>=1){
                if(ll&1){
                    add_edge(i+size,ll+2*size);
                    ll++;
                }
                if(lr&1){
                    add_edge(i+size,lr-1+2*size);
                }
            }
            for(;rl<rr;rl>>=1,rr>>=1){
                if(rl&1){
                    add_edge(i+size,rl+2*size);
                    rl++;
                }
                if(rr&1){
                    add_edge(i+size,rr-1+2*size);
                }
            }
        }
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<LL> x(2*n),id(2*n);
    vector<pair<LL,LL>> c;
    for(int i=0; i<n; ++i){
        cin >> x[2*i] >> x[2*i+1];
        c.emplace_back(x[2*i],2*i);
        c.emplace_back(x[2*i+1],2*i+1);
    }
    sort(c.begin(),c.end());
    for(int i=0; i<2*n; ++i){
        int a=c[i].second;
        id[a]=i;
    }
    auto sat= [&](LL m)->bool{
        stronglyConnectedComponents scc(2*n);
        scc.init(id);
        scc.build(c,m);
        scc.calc();
        for(int i=0; i<2*scc.size; ++i){
            if(scc.scrank[i]==scc.scrank[i+2*scc.size])return false;
        }
        return true;
    };

    LL lb=0,ub=1e9+10;{
        while(ub-lb>1){
            LL mid= (lb+ub)/2;
            if(!sat(mid))ub=mid;
            else lb=mid;
        }
    }
    cout << lb <<"\n";


    return 0;
}

