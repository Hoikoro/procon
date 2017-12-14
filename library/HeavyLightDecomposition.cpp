#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

//verified: AGC005 E Sugigma The Showdown

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
    void add_edge(int a, int b){
        T[a].push_back(Edge(a,b));
        T[b].push_back(Edge(b,a));
    }
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
    bool same(int a,int b){return htop[a]==htop[b];}
    int lca(int a, int b){
        if(index[a]>index[b])swap(a,b);
        if(same(a,b)) return a;
        return lca(a,par[htop[b]]);
    }
    int dist(int a, int b){return dep[a]+dep[b]-2*dep[lca(a,b)];}
    int& operator[](size_t i){return index[i];}
    const int& operator[](size_t i)const{return index[i];}

    //if swapped=1, path s→t is in the same direction as the decomposed queries.
    //Notice : The decomposed queries are closed intervals.
    //クエリをO(logN)個のHeavy path上の区間に分割　閉区間になることに注意.
    //swapped=1の時s→tのパスの方向と分解された区間の始点→終点の方向が同じ.
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

    //edgeをその下端の点のindexで表す
    void decompose_edge_query(int s, int t, vector<pair<int,int>> &queries){
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


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    return 0;
}

