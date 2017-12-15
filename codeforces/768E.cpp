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

struct Problem{
    int n;
    vector<int> s;
    Problem(int n):n(n),s(n){
    };
    using P=pair<int,LL>;
    map<P,int> g;
    int dfs(int a,LL mask){
        if(a==0)return 0;
        auto it=g.find({a,mask});
        if(it!=g.end()){
            DBG(a,mask,it->second)
            return it->second;
        }
        set<int> tmp;
        for(int nxt=1; nxt<=a; ++nxt){
            if(!(mask>>nxt)&1){
                tmp.insert(dfs(a-nxt,mask|(1ll<<nxt)));
            }
        }
        int ret=0;
        for(int i=0; i<=1000; ++i){
            if(tmp.count(i)==0){
                ret=i;
                break;
            }
        }
        g[{a,mask}]=ret;
        return ret;
    }
    void solve(){
        for(int i=0; i<n; ++i){
            cin >> s[i];
        }

        /*vector<int> memo(61);
        for(int i=1; i<=60; ++i){
            memo[i]=dfs(i,0);
            cerr<< memo[i] <<',';
        }*/

        vector<int>memo({0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10});
        LL ans =0;
        for(int i=0; i<n; ++i){
            ans^=memo[s[i]];
        }
        if(ans==0)cout << "YES"<<"\n";
        else cout <<"NO"<<"\n";
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    Problem p(n);
    p.solve();
    return 0;
}

