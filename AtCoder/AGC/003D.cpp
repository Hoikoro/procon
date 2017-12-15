#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
#include <random>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define debug(a) cerr<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

void sieve (LL n,vector<LL> &p){
    vector<char> isprime(n+1,1);
    int cnt=0;
    isprime[0]=isprime[1]=0;
    for(LL i=2; i<=n; i++){
        if(isprime[i]){
            p.push_back(i);
            for(LL j=i*i; j<=n; j+=i) isprime[j]=0;
        }
    }
}
VLL primes;

pair<long long ,long long> remove_cube(long long k){
    LL div=1,a=1,b=1;
    vector<pair<long long ,int>> ret;
    for(int i=0; ;++i){
        if(primes[i]*primes[i]*primes[i]>k){
            break;
        }
        if(k%primes[i]==0){
            ret.push_back(make_pair(primes[i],0));
            LL kk=k;
            while(kk%primes[i]==0){
                kk/=primes[i];
                div*=primes[i];
                (ret.end()-1)->second++;
            }
        }
    }
    REP(i,ret.size()){
        LL p=ret[i].FI,pow=ret[i].SE;
        REP(j,pow%3) a*=p;
        REP(j,(3-pow%3)%3) b*=p;
    }
    if(div!=k){
        LL rest=(LL)round(sqrt(k/div));
        if(rest*rest==k/div){
            a*=rest*rest;
            b*=rest;
        }else{
            a*=k/div;
            if((double)b*k/div*k/div>1e10)b=-1;
            else b*=k/div*k/div;
        }
    }
    //cout << a <<' '<<b<<endl;
    return make_pair(a,b);
}

pair<long long ,long long> pairvec(pair<long long ,long long> a){
    return make_pair(a.SE,a.FI);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    map<pair<long long ,long long >,int> cnt,vis;
    sieve(110000ll,primes);
    int n;
    pair<long long ,long long> s[100010]={};
    cin >> n;
    REP(i,n){
        LL tmp; cin >> tmp;
        s[i]=remove_cube(tmp);
        cnt[s[i]]++;
    }
    LL ans=0;
    REP(i,n){
        if(vis[s[i]]==1) continue;
        if(s[i]==make_pair(1ll,1ll)) {
            ans++;
        }
        else{
            ans+=max(cnt[s[i]],cnt[pairvec(s[i])]);
        }
        vis[s[i]]=1;
        vis[pairvec(s[i])]=1;
    }
    cout << ans <<endl;

    return 0;
}
