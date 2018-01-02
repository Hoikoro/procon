#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first priority_queue

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dbgsplit(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dbgsplit(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}
using LL = long long;
constexpr long long LINF=334ll<<53; constexpr int INF=15<<26; //constexpr long long MOD=1E9+7;
long long modpow(long long a, long long n,long long mod){
    long long i=1,ret=1,p=a;
    while(i<=n){
        if(i&n) ret=(ret*p)%mod;
        i=(i<<1);
        p=(p*p)%mod;
    }
    return ret;
}
pair<long long,long long> solve(LL mod, long long n, vector<long long> &seq){
    if((long long)seq.size()==1){ return {seq[0],1};}
    long long dif=abs(seq[0]-seq[1]),cnt=0;
    sort(seq.begin(),seq.end());
    for(long long i=0; i<(long long)seq.size(); ++i){
        auto it = lower_bound(seq.begin(),seq.end(),(seq[i]+dif)%mod);
        if(it==seq.end())continue;
        if(*it== (seq[i]+dif)%mod) ++cnt;
    }
    long long d=dif*modpow(n-cnt,mod-2,mod)%mod;
    DBG(dif,n,cnt,d)
    long long back=0,forw=0;
    auto it = lower_bound(seq.begin(),seq.end(),(seq[0]+d)%mod);
    for(long long i = (seq[0]+d)%mod;; i=(i+d)%mod,it=lower_bound(seq.begin(),seq.end(),i)){
        if(it==seq.end()) break;
        if(*it!=i) break;
        ++forw;
    }
    it = lower_bound(seq.begin(),seq.end(),(seq[0]-d+mod)%mod);
    for(long long i = (seq[0]-d+mod)%mod;; i=(i-d+mod)%mod,it=lower_bound(seq.begin(),seq.end(),i)){
        if(it==seq.end()) break;
        if(*it!=i) break;
        ++back;
    }
    if(forw+back+1<(long long)seq.size()){return {-1,-1};}
    return {((seq[0]-d*back)%mod+mod)%mod,d};
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    LL mod;
    long long n;
    cin >> mod >> n;
    vector<long long> a(n);
    if(mod==n){
        cout << 0 <<' '<< 1 <<"\n";
        return 0;
    }
    for(long long i=0; i<n; ++i){
        cin >> a[i];
    }
    if(n==1){
        cout << a[0] <<' ' << 0 <<endl;
        return 0;
    }
    pair<long long,long long> ans;
    if(n*2>mod){
        vector<long long> used(mod),b;
        for(long long i=0; i<n; ++i){
            used[a[i]]=1;
        }
        for(long long i=0; i<mod; ++i){
            if(used[i]==0){
                b.push_back(i);
            }
        }
        ans=solve(mod,mod-n,b);
        if(ans.first==-1) {cout << -1 <<"\n";return 0;}
        ans.first=(ans.first+ans.second*(mod-n))%mod;

    }else{
        ans=solve(mod,n,a);
        if(ans.first==-1) {cout << -1 <<"\n"; return 0;}
    }
    cout << ans.first <<' ' << ans.second <<"\n";




    return 0;
}

