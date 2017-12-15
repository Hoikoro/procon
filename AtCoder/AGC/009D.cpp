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
    int from,to;
};
using Graph = vector<vector<Edge>>;

//<f,s>
pair<int,int> dfs(int par, int cur, Graph &t){
    if((int)t[cur].size()==1 and t[cur][0].to==par){
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
    return {max(f,res),(((sum>>res)|1)<<res)};
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    Graph t(n);
    for(int i=0; i<n-1; ++i){
        int a,b;
        cin >> a >>b;
        --a;--b;
        t[a].push_back({a,b});
        t[b].push_back({b,a});
    }
    cout << dfs(-1,0,t).first<<"\n";

    return 0;
}

