#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

struct Problem{
    int n,x,y,z;
    LL ans;
    map<deque<int>,LL> m[41];
    Problem(LL n):n(n),ans(0){};
    long long modpow(long long a, long long n,long long mod=MOD){
        long long i=1,ret=1,p=a;
        while(i<=n){
            if(i&n) ret=(ret*p)%mod;
            i=(i<<1);
            p=(p*p)%mod;
        }
        return ret;
    }
    void solve(){
        cin >> x >> y >> z;
        m[0][{}]=1;
        for(int i=0; i<n; ++i){
            for(auto && v:m[i]){
                deque<int> w;
                for(int j=1; j<=10; ++j){
                    bool haiku=false;
                    w=v.first;
                    for(int k=0; k<(int)w.size(); ++k){
                        if(w[k]!=0){
                            if((w[k]<x and w[k]+j>x) or (w[k]<x+y and w[k]+j>x+y) or(w[k]<x+y+z and w[k]+j>x+y+z)){
                                w[k]=0;
                            }else{
                                w[k]+=j;
                            }
                        }
                        if(w[k]==x+y+z)haiku=true;
                    }
                    if(haiku){
                        //DBG(w,v.first,v.second)
                        ans+=v.second*modpow(10,n-1-i);
                        ans%=MOD;
                    }else{
                        w.push_back(j<=x?j:0);
                        while(!w.empty() and w[0]==0)w.pop_front();
                        m[i+1][w]+=v.second;
                        m[i+1][w]%=MOD;
                    }
                }
            }
        }
        cout << ans <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

