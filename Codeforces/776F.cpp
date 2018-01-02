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
};
using Graph = vector<vector<Edge>>;

struct Problem{
    int n,m;
    Graph g;
    vector<int> ans;
    vector<vector<int>>pol;
    Problem(LL n):n(n),m(m),g(m+1),ans(m+1),pol(m+1){};
    pair<int,int> dfs(int par, int cur, Graph &t){
        if((int)t[cur].size()==1 and t[cur][0].to==par){
            ans[cur]=0;
            return{0,1};
        }
        int sum=0,prd=0,f=0;
        for(auto &e: t[cur]){
            if(e.to!= par){
                auto sub = dfs(cur,e.to,t);
                f=max(f,sub.first);
                prd |= sum&sub.second;
                sum |= sub.second;
            }
        }
        int res=(int)log2((int)t.size())+2;
        while(res>=0 && !(prd&(1<<res)))res--;
        res++;
        while(sum&(1<<res))res++;
        DBG(cur,res,max(f,res),(((sum>>res)|1)<<res))
        ans[cur]=res;
        return {max(f,res),(((sum>>res)|1)<<res)};
    }
    void solve(){
        vector<pair<int,pair<int,int>>> e;
        set<int> v;
        for(int i=0; i<n; ++i){
            v.insert(i);
        }
        for(int i=0; i<m; ++i){
            int a,b;
            cin >> a >>b;
            --a;--b;
            int t=(a-b+n)%n;
            e.emplace_back(t,a,b);
        }
        sort(e.begin(),e.end());
        for(int i=0; i<m; ++i){

        }
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n,m;
    cin >> n  >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

