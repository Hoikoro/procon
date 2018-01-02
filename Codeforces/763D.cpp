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

//双方向木DP
//全方位木DP
//根付き木ハッシュ
random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<LL> dist(1e3, 1e7);
LL b[3]={dist(mt),dist(mt),dist(mt)},p[3]={999999937,MOD,MOD+2},shift[100010];
map<vector<LL>,int> mp;
long long modpow(long long a, long long n,long long mod=MOD){
    long long i=1,ret=1,p=a;
    while(i<=n){
        if(i&n) ret=(ret*p)%mod;
        i=(i<<1);
        p=(p*p)%mod;
    }
    return ret;
}
struct Edge{
    int from,to;
    vector<LL> hash;
    Edge(int from,int to)
        : from(from),to(to),hash(3,0){};
};
typedef vector<vector<Edge>> Graph;
void dfs(int par, int cur, Graph &t,vector<vector<LL>> &h);
void dfs2(int par, int cur, Graph &t,vector<vector<LL>> &h);
pair<int,int> ans;
void remove_(map<vector<LL>,int> &mp, vector<LL> &k){
    auto it = mp.find(k);
    assert(it!=mp.end());
    it->second--;
    if(it->second==0)mp.erase(it);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        shift[i]=dist(rnd);
    }
    if(n==1){cout << 1 <<endl;return 0;}
    Graph t(n);
    vector<vector<LL>> hash(n,vector<LL>(3));
    for(int i=0; i<n-1; ++i){
        int a,b;
        cin >> a >>b;
        --a;--b;
        t[a].push_back(Edge(a,b));
        t[b].push_back(Edge(b,a));
    }

    dfs(-1,0,t,hash);
    dfs2(-1,0,t,hash);

    cout << ans.second+1 <<"\n";
    return 0;
}
void dfs(int par, int cur, Graph &t,vector<vector<LL>> &h){
    auto par_id = &t[cur][0];
    if((int)t[cur].size()==1 and t[cur][0].to==par){
        t[cur][0].hash={0,1,1};
        h[cur]={0,1,1};
    }else{
        LL height=0;
        vector<vector<LL>> tmp;
        for(auto &e : t[cur]){
            if(e.to!=par){
                dfs(cur,e.to,t,h);
                tmp.push_back(h[e.to]);
                height=max(height,h[e.to][0]+1);
            }else{
                par_id=&e;
            }
        }
        sort(tmp.begin(),tmp.end());
        h[cur]={height,1,1};
        for(int i=0; i<(int)tmp.size(); ++i){
            for(int j=1; j<3; ++j){
                h[cur][j]=h[cur][j]*(shift[height]+tmp[i][j])%p[j];
            }
        }
    }
    par_id->hash=h[cur];
    mp[h[cur]]++;
    DBG(cur,h[cur][0],h[cur][1],h[cur][2])
}
void dfs2(int par, int cur, Graph &t,vector<vector<LL>> &h){
    auto par_id = &t[cur][0];
    vector<pair<vector<LL>,int>> tmp;
    unordered_map<int,vector<LL>> hashes;
    LL height[2]={};
    vector<LL> rh={0,1,1},its_sub={0,1,1};
    for(auto &e : t[cur]){
        if(e.to==par)par_id= &e;
        DBG(cur,e.to,h[e.to][1],h[e.to][2])
        tmp.emplace_back(h[e.to],e.to);
        if(h[e.to][0]+1>height[1])height[1]=h[e.to][0]+1;
        if(height[1]>height[0])swap(height[1],height[0]);
    }
    sort(tmp.begin(),tmp.end());
    for(int i=0; i<(int)tmp.size(); ++i){
        for(int j=1; j<3; ++j){
                its_sub[j]=its_sub[j]*(shift[height[0]]+tmp[i].first[j])%p[j];
        }
    }
    its_sub[0]=height[0];
    remove_(mp,h[cur]);
    mp[its_sub]++;
    DBG(par,cur,mp.size())
    DBG(par,cur,h[cur][0],h[cur][1],h[cur][2])
    DBG(par,cur,its_sub[0],its_sub[1],its_sub[2])
    if(ans.first<mp.size()){
        ans={mp.size(),cur};
    }
    remove_(mp,its_sub);

    for(int i=0; i<(int)tmp.size()-1; ++i){
        rh[0]=height[0];
        for(int j=1; j<3; ++j){
                rh[j]=its_sub[j]*modpow(shift[height[0]]+tmp[i].first[j],p[j]-2,p[j])%p[j];
        }
        hashes[tmp[i].second]=rh;
    }
    rh[0]=height[1];rh[1]=1,rh[2]=1;
    for(int i=0; i<(int)tmp.size()-1; ++i){
        for(int j=1; j<3; ++j){
            rh[j]=rh[j]*(shift[height[1]]+tmp[i].first[j])%p[j];
        }
    }
    hashes[tmp.back().second]=rh;


    for(auto &e : t[cur]){
        if(e.to!=par){
            h[cur]=hashes[e.to];
            mp[h[cur]]++;
            DBG(cur,e.to,h[cur][0],h[cur][1],h[cur][2])
            dfs2(cur,e.to,t,h);
            remove_(mp,h[cur]);
        }
    }
    h[cur]=par_id->hash;
    mp[h[cur]]++;
    DBG(h[cur][0],h[cur][1],h[cur][2])
    DBG("")
}


