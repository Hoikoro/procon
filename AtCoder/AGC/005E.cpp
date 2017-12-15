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
using Graph = vector<vector<Edge>> ;

struct HeavyLightDecomposition{
    vector<int> index, htop, hchild, par, dep, idtov, topo,sub,heads;
    Graph T;
    HeavyLightDecomposition(int n) :index(n,-1),htop(n),hchild(n,-1),par(n),dep(n),idtov(n),sub(n),T(n){}

    void calc(int root){
        queue<int> Q({root});
        par[root]=-1;
        while(!Q.empty()){
            int curr=Q.front(); Q.pop(); topo.push_back(curr);
            for(auto &x: T[curr]){
                if(x.to!=par[curr]){
                    par[x.to]=curr;
                    Q.push(x.to);
                    dep[x.to]=dep[curr]+1;
                }
            }
        }
        for(int i=par.size()-1,max_sub=0; i>=0; --i){
            ++sub[topo[i]];
            if(i>0)sub[par[topo[i]]]+=sub[topo[i]];
            if(i>0 and i<par.size()-1)if(par[topo[i+1]]!=par[topo[i]])max_sub=0;
            if(i>0 and sub[topo[i]]>max_sub) {
                hchild[par[topo[i]]]=topo[i];
                max_sub=sub[topo[i]];
            }
            for(auto &x : T[topo[i]])if(x.to!=par[topo[i]] and x.to!=hchild[topo[i]]) heads.push_back(x.to);
        }
        heads.push_back(root);
        reverse(heads.begin(),heads.end());
        DBG(heads.size())
        int id=0;
        for(int x : heads) {
            for(int i=x; i!=-1; i=hchild[i]){
                index[i]=id++;
                idtov[index[i]]=i;
                htop[i]=x;
            }
        }
    }
    inline bool same(int a,int b){return htop[a]==htop[b];}

    int lca(int a, int b,int cnt=0){
        if(index[a]>index[b])swap(a,b);
        if(same(a,b)) {DBG(cnt)return a;}
        return lca(a,par[htop[b]],cnt+1);
    }
    int dist(int a, int b){
        return dep[a]+dep[b]-2*dep[lca(a,b)];
    }
};

template<class T1, class T2, class T3> struct Problem{
    int size,x,y;
    HeavyLightDecomposition sigma,sugim;
    Problem(T1 x):size(x),sigma(x),sugim(x){};

    int dfs(int par, int cur, int d){
        int d2=sugim.dist(cur,y);
        if(d>=d2) return -INF;
        if(sigma.T[cur].size()==1 and sigma.T[cur][0].to==par){
            return d2;
        }
        int ret=d2;
        for(auto e: sigma.T[cur]){
            if(e.to!=par){
                if(sugim.dist(cur,e.to)>=3) return INF;
                ret=max(ret,dfs(cur,e.to,d+1));
            }
        }
        return ret;
    }

    void solve(){
        cin >> x >> y;
        --x;--y;
        for(int i=0; i<size-1; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            sigma.T[a].push_back(Edge(a,b));
            sigma.T[b].push_back(Edge(b,a));
        }
        for(int i=0; i<size-1; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            sugim.T[a].push_back(Edge(a,b));
            sugim.T[b].push_back(Edge(b,a));
        }
        //sigma.calc(x);
        sugim.calc(y);
        int ans=dfs(-1,x,0);
        if(ans==INF)cout << -1 <<"\n";
        else cout << ans*2<<"\n";
    }

};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a,b,c;
    cin >> a;
    Problem<decltype(a),decltype(b),decltype(c)> e(a);
    e.solve();

    return 0;
}

