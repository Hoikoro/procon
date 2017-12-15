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
    //if swapped=1, path s→t is in the same direction as the decomposed queries.
    //Notice : The decomposed queries are closed intervals.
    void decompose_vertex_query(int s, int t, vector<pair<int,int>> &queries){
        for(int swapped=0;;){
            if(index[s]<index[t]){
                swap(s,t);
                swapped^=1;;
            }
            if(same(s,t)){
                queries.emplace_back(index[t],index[s]);
                break;
            }
            queries.emplace_back(index[htop[s]],index[s]);
            s=par[htop[s]];
        }
    }
    int& operator[](size_t i){return index[i];}
    const int& operator[](size_t i)const{return index[i];}
};
struct RangeMin{
    using T = int;
    T operator()(const T &a, const T &b){return min(a,b);}
    static constexpr T id(){return T(INF);};
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
    }
    explicit SegmentTree(vector<Val> &v){
        n = 1;
        while(n < v.size()) n <<=1;
        data = vector<Val> (n<<1);
        copy(v.begin(),v.end(),data.begin()+n);
        for(int i=n+(int)v.size(); i<2*n;i++)data[i]=calc.id();
        for(int i=n-1; i>0; --i){data[i]=calc(data[i*2],data[i*2+1]);}
    }
    void update(int i,Val v){
        int k = i + n;
        data[k] = v;
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
    int n,q;
    vector<int> s;
    HeavyLightDecomposition hld;
    SegmentTree<RangeMin> seg,rseg;
    Problem(LL n):n(n),s(n),hld(n),seg(0),rseg(0){};
    void solve(){
        cin >> q;
        for(int i=0; i<n-1; ++i){
            int a,b;
            cin >> a >> b;
            --a;--b;
            hld.T[a].emplace_back(a,b);
            hld.T[b].emplace_back(b,a);
        }
        hld.calc(0);
        string str;
        cin >> str;
        queue<int> Q;
        vector<int> dist(n,-1),dist2;
        for(int i=0; i<n; ++i){
            if(str[i]=='1'){
                dist[hld[i]]=0;
                Q.push(i);
            }
        }
        while(!Q.empty()){
            int t=Q.front();
            Q.pop();
            for(auto && x:hld.T[t]){
                if(dist[hld[x.to]]<0){
                    dist[hld[x.to]]=dist[hld[t]]+3;
                    Q.push(x.to);
                }
            }
        }
        if(dist[0]==-1) dist=vector<int>(n,INF);
        dist2=dist;
        for(int i=0; i<n; ++i){
            dist[hld[i]]-=hld.dep[i]; //going up
            dist2[hld[i]]+=hld.dep[i]; //going down
        }
        seg = SegmentTree<RangeMin>(dist);
        rseg = SegmentTree<RangeMin>(dist2);
        for(int i=0; i<q; ++i){
            int s,t,ans,lca;
            vector<pair<int,int>> query,rquery;
            cin >> s >> t;
            --s;--t;
            int d=seg.query(hld[t],hld[t]+1)+hld.dep[t]; //= dist[hld[i]]
            seg.update(hld[t],-hld.dep[t]);
            rseg.update(hld[t],hld.dep[t]);
            ans = hld.dist(s,t);
            lca = hld.lca(s,t);
            hld.decompose_vertex_query(s,lca,query);
            hld.decompose_vertex_query(lca,t,rquery);
            int add=INF,radd=INF;
            for(auto x:query){
                add=min(add,seg.query(x.first,x.second+1));
            }
            for(auto x: rquery){
                radd=min(radd,rseg.query(x.first,x.second+1));
            }
            add+=hld.dep[s];
            radd=radd-hld.dep[lca]*2+hld.dep[s];
            cout << ans+min(add,radd) <<"\n";
            seg.update(hld[t],d-hld.dep[t]);
            rseg.update(hld[t],d+hld.dep[t]);
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

