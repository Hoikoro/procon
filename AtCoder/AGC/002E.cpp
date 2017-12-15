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

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    a.push_back(INF);
    a.push_back(0);
    sort(a.begin(),a.end(),greater<int>());
    int l1=0,u1=n+1;
    while(u1-l1>1){
        int m1=(u1+l1)/2;
        if(a[m1]<=m1)u1=m1;
        else l1=m1;
    }
    int l2=u1,u2=n+1;
    while(u2-l2>1){
        int m2=(l2+u2)/2;
        if(a[m2]==a[u1])l2=m2;
        else u2=m2;
    }
    bool ans;
    if(a[u1]==u1){
        ans=(l2-u1)%2==1;
    }else if(a[u1]-u1==-1){
        ans=((l2-u1)%2==0)||((a[u1-1]-a[u1])%2==1);
    }else{
        ans=((a[u1-1]-(u1-1))%2==1);
    }
    cout << (ans?"First":"Second") <<"\n";

    return 0;
}

