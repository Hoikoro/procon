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
    Problem(int n):n(n),s(n){};

    void solve(){
        map<int,int> m;
        for(int i=0; i<n; ++i){
            cin >> s[i];
            m[s[i]]++;
        }
        int ans;
        if(m.size()<=2)ans=0;
        else{
            ans=n;
            ans-=m.begin()->second;
            auto it=m.end();
            it--;
            ans-=it->second;
        }
        cout <<ans <<"\n";
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

