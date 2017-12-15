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
    int from,to,used;
};
using Graph = vector<vector<Edge>>;

set<int> l[200020];
int failcnt = 0, root = -1;
void fail(){cout << -1 <<"\n"; exit(0);}
void ok(int root){
    int ans = 0;
    for(auto x : l[root])ans+=x;
    while(ans%2==0) ans /= 2;
    cout << ans <<"\n";
    exit(0);
}
int dfs(int par, int cur, Graph &t){
    if((int)t[cur].size()==1 and t[cur][0].to == par){
        return 1;
    }
    for(auto &e : t[cur]){
        if(e.to != par && !e.used){
            int tmp = dfs(cur, e.to, t);
            e.used=1;
            if(tmp == -1){
                failcnt++;
                if(failcnt>=2)fail();
                dfs(-1,root,t);
                if((int)l[root].size()>2)fail();
                else {
                    ok(root);
                }
            }else{
                l[cur].insert(tmp);
            }
        }
    }
    if(l[cur].size()==1) {return *l[cur].begin()+1;}
    else{
        root=cur;
        return -1;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    Graph t(n);
    for(int i=0; i<n-1; ++i){
        int a,b;
        cin >> a >> b;
        --a;--b;
        t[a].push_back({a,b,0});
        t[b].push_back({b,a,0});
    }
    dfs(-1,0,t);
    if((int)l[0].size()>2)fail();
    ok(0);

    return 0;
}

