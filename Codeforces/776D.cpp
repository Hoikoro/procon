#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dbgsplit(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...) ;
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

struct StronglyConnectedComponents{
    vector<int> scrank,vis,po;
    Graph graph,rgraph;
    StronglyConnectedComponents(int n):scrank(n),vis(n),graph(n),rgraph(n){}
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
    void add_edge(int a, int b){
        graph[a].emplace_back(a,b);
        rgraph[b].emplace_back(b,a);
    }
};

struct Problem{
    int n,m;
    vector<int> is_unlocked;
    vector<vector<int>> swc;
    StronglyConnectedComponents scc;
    Problem(LL n, LL m):n(n),m(m),is_unlocked(n),swc(n),scc(2*m){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> is_unlocked[i];
        }
        for(int i=0; i<m; ++i){
            int loop;
            cin >> loop;
            for(int j=0; j<loop; ++j){
                int tmp;
                cin >> tmp;
                swc[--tmp].push_back(i);
            }
        }
        for(int i=0; i<n; ++i){
            if(is_unlocked[i]==1){
                scc.add_edge(2*swc[i][0],2*swc[i][1]);
                scc.add_edge(2*swc[i][1],2*swc[i][0]);
                scc.add_edge(2*swc[i][0]+1,2*swc[i][1]+1);
                scc.add_edge(2*swc[i][1]+1,2*swc[i][0]+1);
            }else{
                scc.add_edge(2*swc[i][0],2*swc[i][1]+1);
                scc.add_edge(2*swc[i][1],2*swc[i][0]+1);
                scc.add_edge(2*swc[i][0]+1,2*swc[i][1]);
                scc.add_edge(2*swc[i][1]+1,2*swc[i][0]);
            }
        }
        scc.calc();
        for(int i=0; i<m; ++i){
            if(scc.scrank[2*i]==scc.scrank[2*i+1]){
                cout << "NO" <<"\n";
                return;
            }
        }
        cout << "YES"<<"\n";
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

