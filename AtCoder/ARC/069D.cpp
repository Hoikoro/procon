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

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    vector<int> ans(n),res;
    for(int i=0; i<4; ++i){
        ans[0]=i/2;
        ans[1]=i%2;
        for(int i=2; i<n; ++i){
            if(ans[i-1]==0 && s[i-1] =='o')ans[i]=ans[i-2];
            if(ans[i-1]==0 && s[i-1] =='x')ans[i]=ans[i-2]^1;
            if(ans[i-1]==1 && s[i-1] =='o')ans[i]=ans[i-2]^1;
            if(ans[i-1]==1 && s[i-1] =='x')ans[i]=ans[i-2];
        }
        if("xo"[(ans[n-2]==ans[0])^ans[n-1]]!=s[n-1])continue;
        if("xo"[(ans[n-1]==ans[1])^ans[0]]!=s[0])continue;
        res=ans;
        break;
    }

    if(res.size()==0)cout << -1 <<"\n";
    else{
        for(int i=0; i<res.size(); ++i){
            cout << "SW"[res[i]];
        }
        cout <<"\n";
    }

    return 0;
}

