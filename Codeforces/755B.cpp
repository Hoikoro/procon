#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#define DBG(...) {string dst__=#__VA_ARGS__;dreplace(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dreplace(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    set<string> p,e;
    for(int i=0; i<n; ++i){
        string tmp;
        cin >> tmp;
        p.insert(tmp);
    }
    for(int i=0; i<m; ++i){
        string tmp;
        cin >> tmp;
        e.insert(tmp);
    }

    int com=0;
    for(string x : p){
        if(e.count(x))++com;
    }
    bool ans;
    if(com%2==1){
        if(n>=m)ans=true;
        else ans=false;
    }else{
        if(n>m)ans=true;
        else ans=false;
    }

    if(ans)cout << "YES" <<"\n";
    else cout << "NO" <<"\n";

    return 0;
}

