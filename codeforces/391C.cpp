#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

string dst__; stringstream dss__;
#define DBG(...) dst__=#__VA_ARGS__;replace(dst__.begin(),dst__.end(),',',' ');dss__.str("");dss__.clear(stringstream::goodbit); dss__<<dst__; debug(dss__,__VA_ARGS__);
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

long long modpow(long long a, long long n,long long mod){
    long long i=1,ret=1,p=a;
    while(i<=n){
        if(i&n) ret=(ret*p)%mod;
        i=(i<<1);
        p=(p*p)%mod;
    }
    return ret;
}

int main(){
    //cin.tie(0);
    //ios_base::sync_with_stdio(false);
    random_device rand;
    mt19937 mt(rand());
    uniform_int_distribution<LL> dist(1, 1e7);
    LL b[2]={dist(mt),dist(mt)},p[2]={999999937,MOD};
    int n,m;
    scanf("%d%d",&n, &m);
    vector<PLL> h(m,make_pair(1ll,1ll));
    vector<int> used(m,-1);
    LL pow[2]={1ll,1ll};
    for(int i=0; i<n; ++i){
        for(int j=0; j<2; ++j){
            pow[j]=pow[j]*b[j]%p[j];
        }
        map<int,int> cnt;
        //VI cnt(m);
        //VI vis;
        int pokemons,tmp;
        scanf("%d",&pokemons);
        for(int j=0; j<pokemons; ++j){
            scanf("%d",&tmp);
            ++cnt[--tmp];
            //vis.push_back(tmp);
        }
        for(auto &x : cnt){
            //h[x].first=(h[x].first*modpow(b[0],i-used[x],p[0])+cnt[x])%p[0];
            h[x.first].first=(h[x.first].first*pow[0]+x.second)%p[0];
            //h[x].second=(h[x].second*modpow(b[1],i-used[x],p[1])+cnt[x])%p[1];
            h[x.first].second=(h[x.first].second*pow[1]+x.second)%p[1];
            //used[x]=i;
        }
    }
    /*for(int x=0; x<m; ++x){
        h[x].first=(h[x].first*modpow(b[0],n-used[x],p[0]))%p[0];
        h[x].second=(h[x].second*modpow(b[1],n-used[x],p[1]))%p[1];
    }*/

    sort(h.begin(),h.end());
    LL ans=1,same=1,fac=1;
    for(int i=0; i<m-1; ++i){
        if(h[i]==h[i+1]){
            same++;
            fac=fac*same%MOD;
        }else{
            ans=ans*fac%MOD;
            same=1;
            fac=1;
        }
    }
    ans=ans*fac%MOD;
    cout << ans <<endl;



    return 0;
}

