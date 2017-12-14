#include <bits/stdc++.h>
using namespace std;

#define DBG(...)
using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

//関節点の個数をAP_countとする　0~AP_count-1を関節点に、AP_count~を二重連結成分に割り当てる
//is_AP: 関節点→index, それ以外→-1
//AP_inv: 関節点index→頂点番号
//biccrank:頂点が属する二重連結成分(関節点でも1つしか値を持たないことに注意。必要ならtreeの隣接成分を調べる)
//bicc:bicc[i]は(i+AP_count)に属する頂点集合
//tree: 関節点と二重連結成分をそれぞれ1頂点に縮約した木

struct Edge{
    int from,to;
    bool local=true,in_dfstree=false;
    Edge(int from,int to)
        : from(from),to(to){};
    Edge(){Edge(0,0);}
};
typedef vector<vector<Edge>> Graph;
struct ArticulationPoints{
    vector<int> ord,low,biccrank,ordered_v,is_AP,AP_inv;
    vector<vector<int>> bicc,tree;/*頂点→連結成分*//*関節点←→連結成分*/
    int root_cnt=0,AP_count=0,cnt=0;
    Graph g;
    ArticulationPoints(int n): ord(n,-1),low(n,INF),biccrank(n,-1),is_AP(n,-1){}
private:
    int dfs(int par, int cur){ //一つ前、現在位置、頂点を何個見たか
        if(ord[cur]>=0)return ord[cur];
        DBG(par,cur)
        ord[cur]=cnt++;
        low[cur]=min(ord[cur],low[cur]);
        ordered_v.push_back(cur);
        for(auto &x : g[cur]){
            if(x.to!=par && !(ord[x.to]>ord[cur])){
                if(ord[x.to]<0) x.in_dfstree=true;
                int tmp=dfs(cur,x.to);
                DBG(cur,x.to,tmp)
                if(cur==0){
                    if(x.in_dfstree)++root_cnt;
                    if(root_cnt>=2){
                        if(is_AP[cur]<0)AP_inv.push_back(cur),is_AP[cur]=AP_count++;
                        x.local=false;
                    }
                }else{
                    low[cur]=min(low[cur],tmp);
                    if(ord[cur]<=tmp){
                        if(is_AP[cur]<0)AP_inv.push_back(cur),is_AP[cur]=AP_count++;
                        DBG(x.from,x.to)
                        x.local=false;
                    }
                }
            }
        }
        return low[cur];
    }
    void AP_divided_dfs(int par, int cur){//一つ前、現在位置、関節点個数=AP_count
        int bicc_cnt=0;
        queue<pair<int,int>> Q({{par,cur}});
        tree.resize(AP_count+1);
        function <void (int,int)> local_dfs=[&](int p, int c){
            DBG(p,c)
            for(auto &x : g[c]){
                DBG(x.from,x.to)
                if(x.in_dfstree){
                    if(x.local){
                        DBG('a',x.to)
                        biccrank[x.to]=AP_count+bicc_cnt;
                        bicc[bicc_cnt].push_back(x.to);
                        local_dfs(c,x.to);
                    }else{
                        DBG('b',c)
                        Q.emplace(c,x.to);
                        if(tree[is_AP[c]].empty()){
                            tree[AP_count+bicc_cnt].push_back(is_AP[c]);
                            tree[is_AP[c]].push_back(AP_count+bicc_cnt);
                        }
                    }
                }
            }
        };
        while(!Q.empty()){
            int fi,se;
            tie(fi,se)=Q.front();
            bicc.push_back({});
            if(fi!=-1){
                bicc[bicc_cnt].push_back(fi);
                tree.push_back({});
                DBG(AP_count+bicc_cnt,is_AP[fi])
                tree[AP_count+bicc_cnt].push_back(is_AP[fi]);
                tree[is_AP[fi]].push_back(AP_count+bicc_cnt);
            }
            biccrank[se]=AP_count+bicc_cnt;
            bicc[bicc_cnt].push_back(se);
            local_dfs(fi,se);
            Q.pop();
            bicc_cnt++;
        }
    }
public:
    //二重連結成分をまとめた木をtreeにつくる
    void calc(int root=0){
        dfs(-1,root);
        for(int i=0; i<g.size(); ++i){
            DBG(i,is_AP[i])
        }
        AP_divided_dfs(-1,root);
    }
    void add_edge(int a, int b){
        g[a].push_back(Edge(a,b));
        g[b].push_back(Edge(b,a));
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    ArticulationPoints ap(n);
    for(int i=0; i<m; ++i){
        int a,b;
        cin >> a >> b;
        ap.add_edge(a,b);
    }
    ap.calc();
    for(int i=0; i<n; ++i){
        DBG(i,ap.biccrank[i]);
    }
    for(int i=0; i<ap.tree.size(); ++i){
        cout << i<<' ';
        for(int j=0; j<ap.tree[i].size(); ++j){
            cout << ap.tree[i][j]<<' ';
        }
        cout <<endl;
    }
    for(int i=0; i<ap.bicc.size(); ++i){
        cout << i+ap.AP_count<<' ';
        for(int j=0; j<ap.bicc[i].size(); ++j){
            cout << ap.bicc[i][j]<<' ';
        }
        cout <<endl;
    }



    return 0;
}

