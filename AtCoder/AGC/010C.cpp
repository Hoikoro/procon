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
    Edge(int from,int to)
        : from(from),to(to) {};
};
typedef vector<vector<Edge>> Graph;




void ok(){cout << "YES" <<"\n"; exit(0);}
void fail(){cout << "NO" <<"\n"; exit(0);}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n),upward(n),l(n),u(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    Graph t(n);
    for(int i=0; i<n-1; ++i){
        int a,b;
        cin >> a >> b;
        --a;--b;
        t[a].push_back(Edge(a,b));
        t[b].push_back(Edge(b,a));
    }
    if(n==2){
        if(a[0]==a[1])ok();
        else fail();
    }

    int root=0;
    for(int i=0; i<n; ++i){
        if((int)t[i].size()>1){
            root=i;
        }
    }

    function <void(int,int)> dfs = [&](int par, int cur){
        if((int)t[cur].size()==1){
            upward[cur]=a[cur];
            return;
        }
        int ub=0,sum=0;
        for(auto &e : t[cur]){
            if(e.to!=par){
                dfs(cur,e.to);
                sum+=upward[e.to];
                ub=max(ub,upward[e.to]);
            }
        }
        if(sum<a[cur])fail();
        upward[cur]=a[cur]*2-sum;
        if(upward[cur]<0) fail();
        if(ub>a[cur]) fail();
    };


    dfs(-1,root);
    if(upward[root]==0)ok();
    else fail();


    return 0;
}

