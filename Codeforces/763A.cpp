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
constexpr long long LINF=334ll<<53; constexpr int INF=15<<26; constexpr long long MOD=1E9+7;

struct Edge{
    int from,to,c;
    Edge(int from, int to):from(from),to(to),c(0){};
};
typedef vector<vector<Edge>> Graph;
int cut=-1;
int dfs(int root, int par, int cur, Graph &t,vector<int> &color){
    if((int)t[cur].size()==1 and t[cur][0].to==par) return color[cur];
    int c=color[cur];
    for(auto e: t[cur]){
        if(e.to!=par){
            int tmp=dfs(root,cur,e.to,t,color);
            if(tmp==-1)return -1;
            if(cur!=root and c!=tmp){
                cut = cur;
                return -1;
            }else{
                c=tmp;
            }
        }
    }
    return c;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    Graph t(n);
    vector<int> c(n),dep;
    for(int i=0; i<n-1; ++i){
        int a,b;
        cin >> a >>b;
        --a;--b;
        t[a].push_back(Edge(a,b));
        t[b].push_back(Edge(b,a));
    }

    for(int i=0; i<n; ++i){
        cin >> c[i];
    }
    int a=dfs(0,-1,0,t,c);
    if(a!=-1){
        cout <<"YES"<<"\n";
        cout << 1 <<"\n";
    }else{
        int b=dfs(cut,-1,cut,t,c);
        if(b!=-1){
            cout <<"YES"<<"\n";
            cout << cut+1 <<"\n";

        }else{
            cout <<"NO" <<"\n";
        }
    }



    return 0;
}

