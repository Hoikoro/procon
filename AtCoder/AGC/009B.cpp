#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#ifdef DEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dreplace(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dreplace(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
template<typename T> using V = vector<T>;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

struct Edge{
    int from,to;
    Edge(int from,int to)
        : from(from),to(to) {};
};
typedef vector<vector<Edge>> Graph;

int defineDepth(Graph &T, vector<int> &p, vector<int> &dep,vector<vector<int>> &dtov,int root){
    fill(p.begin(),p.end(),-1);
    int ret =0;
    queue<int> Q;
    Q.push(root);
    p[root]=root;
    dtov[0].push_back(root);
    while(!Q.empty()){
        int nex=Q.front();
        Q.pop();
        for(auto &x: T[nex]){
            if(p[x.to]==-1){
                p[x.to]=x.from;
                Q.push(x.to);
                dep[x.to]=dep[x.from]+1;
                ret=max(ret,dep[x.to]);
                dtov[dep[x.to]].push_back(x.to);
            }
        }
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    Graph t(n);
    vector<int> dep(n),par(n),dp(n);
    vector<vector<int>> dtov(n);
    for(int i=1; i<n; ++i){
        int tmp;
        cin >> tmp; --tmp;
        t[tmp].push_back(Edge(tmp,i));
        t[i].push_back(Edge(i,tmp));
    }
    int deepest=defineDepth(t,par,dep,dtov,0);
    for(int i=deepest; i>=0; --i){
        for(int x : dtov[i]){
            VI tmp;
            for(auto &e : t[x]){
                if(e.to==par[x])continue;
                tmp.push_back(dp[e.to]);
            }
            sort(tmp.begin(),tmp.end(),greater<int>());
            for(int j=0; j<tmp.size(); ++j){
                dp[x]=max(dp[x],tmp[j]+j+1);
            }
        }
    }
    cout << dp[0] <<endl;


    return 0;
}

