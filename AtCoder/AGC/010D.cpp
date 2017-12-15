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
long long gcd(long long a, long long b){
    while(b){a%=b;swap(a,b);}
    return a;
}
bool dfs(vector<long long> &a){
    int even=0,odd=0,odd_id,g=0;
    for(int i=0; i<(int)a.size(); ++i){
        if(a[i]%2==0)even++;
        else {odd++; odd_id=i;}
    }
    if(even%2==1)return true;
    if(odd>1)return false;
    if(a[odd_id]==1)return false;
    a[odd_id]--;
    for(int i=0; i<(int)a.size(); ++i){
        g=gcd(g,a[i]);
    }
    for(int i=0; i<(int)a.size(); ++i){
        a[i]/=g;
    }
    return !dfs(a);
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<LL> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    cout << (dfs(a)?"First":"Second") <<"\n";


    return 0;
}


