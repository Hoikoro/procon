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

struct Edge{
    int from,to;
    Edge(int from,int to)
        : from(from),to(to){};
    Edge(){Edge(0,0);}
};
using Graph = vector<vector<Edge>>;
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
        if(same(a,b)) {return a;}
        return lca(a,par[htop[b]],cnt+1);
    }
    int dist(int a, int b){
        return dep[a]+dep[b]-2*dep[lca(a,b)];
    }
    void decompose_vertex_query(int s, int t, vector<pair<int,int>> &queries){
        for(int swapped=0;;){
            if(index[s]<index[t]){
                swap(s,t);
                swapped^=1;
            }
            if(same(s,t)){
                if(s!=t)queries.emplace_back(index[t]+1,index[s]);
                break;
            }
            queries.emplace_back(index[htop[s]],index[s]);
            s=par[htop[s]];
        }
    }
};

struct RangeSum{
    using T = pair<int,int>;
    T operator()(const T &a, const T &b){
        if(a.second==-1)return {a.first+b.first,b.second};
        else return {a.first+b.first,a.second};
    }
    static constexpr T id(){return T(0,-1);};
};

template<typename M>
struct SegmentTree{
    using Val = typename M::T;
    M calc;
    vector<Val> data;
    int n;
    explicit SegmentTree(int size){
        n = 1;
        while(n < size) n <<=1;
        data = vector<Val>(n<<1,calc.id());
        for(int i=0; i<size; ++i){
            data[i+n]={1,i};
        }
        for(int i=n-1; i>0; --i){data[i]=calc(data[i*2],data[i*2+1]);DBG(i,data[i])}
    }
    explicit SegmentTree(vector<Val> &v){
        n = 1;
        while(n < v.size()) n <<=1;
        data = vector<Val> (n<<1);
        copy(v.begin(),v.end(),data.begin()+n);
        for(int i=n+(int)v.size(); i<2*n;i++)data[i]=calc.id();
        for(int i=n-1; i>0; --i){data[i]=calc(data[i*2],data[i*2+1]);}
    }
    void update(int i){
        int k = i + n;
        data[k] = {0,-1};
        for(k>>=1; k>=1; k>>=1)data[k] = calc(data[k*2],data[k*2+1]);
    }
    Val query(int l,int r){ //get[a,b)
        Val resl=calc.id(),resr=calc.id();
        for(l += n, r += n; l<r; l>>=1, r>>=1){
            if(l&1)resl=calc(resl, data[l++]);
            if(r&1)resr=calc(data[r-1],resr);
        }
        return calc(resl,resr);
    }
};

struct Problem{
    int n;
    SegmentTree<RangeSum> seg;
    HeavyLightDecomposition start,goal;
    map<pair<int,int>,int> mp;
    vector<pair<int,int>> edges;
    vector<int> vis;
    Problem(LL n):n(n),seg(n),start(n),goal(n),vis(n){};
    void push_edge(int from, int to, queue<int> &Q){
        vector<pair<int,int>> q;
        start.decompose_vertex_query(from,to,q);
        int dist=0,pos=-1;
        for(auto &e :q){
            if(e.first>e.second)swap(e.first,e.second);
            DBG(e)
            auto tmp=seg.query(e.first,e.second+1);
            dist+=tmp.first;
            pos=max(pos,tmp.second);
        }
        DBG(from,to,dist,pos)
        if(dist==1){
            Q.push(mp[{from,to}]);
            seg.update(pos);
        }
    }
    void refill(queue<int> &Q){
        for(int i=0; i<n-1; ++i){
            if(vis[i]==0){
                int from=edges[i].first,to=edges[i].second;
                push_edge(from,to,Q);
            }
        }
    }
    void solve(){
        for(int i=0; i<n-1; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            start.T[a].push_back(Edge(a,b));
            start.T[b].push_back(Edge(b,a));
        }
        for(int i=0; i<n-1; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            if(a>b) swap(a,b);
            goal.T[a].push_back(Edge(a,b));
            goal.T[b].push_back(Edge(b,a));
            mp[{a,b}]=i;
            edges.emplace_back(a,b);
        }
        int cnt=0;
        start.calc(0);
        queue<int> Q;
        for(int i=0; i<n-1; ++i){
            if(start.dist(edges[i].first,edges[i].second)==1){
                Q.push(i);
                vis[i]=1;
                int tmp=max(start.index[edges[i].first],start.index[edges[i].second]);
                seg.update(tmp);
            }
        }
        while(!Q.empty()){
            while(!Q.empty()){
                int a=edges[Q.front()].first;
                int b=edges[Q.front()].second;
                vis[Q.front()]=1;
                Q.pop();
                DBG(a,b)
                ++cnt;
                int tmp=max(start.index[a],start.index[b]);
                seg.update(tmp);
                for(auto x: goal.T[a]){
                    int to=x.to,from=a;
                    if(from>to) swap(from,to);
                    if(vis[mp[{from,to}]]==0){
                        push_edge(from,to,Q);
                    }
                }
                for(auto x: goal.T[b]){
                    int to=x.to,from=b;
                    if(from>to) swap(from,to);
                    if(vis[mp[{from,to}]]==0){
                        push_edge(from,to,Q);
                    }
                }
            }
            refill(Q);
        }

        if(cnt==n-1)cout << "YES" <<"\n";
        else cout <<"NO" <<"\n";
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

