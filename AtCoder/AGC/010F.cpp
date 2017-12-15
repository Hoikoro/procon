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
    cin >> n;
    vector<int> stone(n),deg(n),ans;
    vector<vector<int>> to(n);
    for(int i=0; i<n; ++i){
        cin >> stone[i];
    }
    for(int i=0; i<n-1; ++i){
        int a,b;
        cin >> a >> b;
        --a;--b;
        if(stone[a]>stone[b]){
            to[b].push_back(a);
            deg[a]++;
        }else if (stone[a]<stone[b]){
            to[a].push_back(b);
            deg[b]++;
        }
    }
    unordered_set<int> st;
    for(int i=0; i<n; ++i){
        st.insert(i);
    }
    while((int)st.size()>0){
        set<int> to_erase;
        set<pair<int,int>> to_decrease;
        for(auto &x : st){
            if(deg[x]==0){
                to_erase.insert(x);
                for(auto &y : to[x]){
                    ans.push_back(y);
                    to_erase.insert(y);
                    for(auto &z: to[y])to_decrease.insert({y,z});
                }
            }
        }
        for(auto &z: to_decrease)deg[z.second]--;
        for(auto &z: to_erase){st.erase(z);}
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(int i=0; i<(int)ans.size(); ++i){
        cout<<ans[i]+1;
        if(i==(int)ans.size()-1)cout <<"\n";
        else cout <<' ';
    }
    return 0;
}

