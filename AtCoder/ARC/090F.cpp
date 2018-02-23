#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;
#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif


namespace Solver{
using namespace std;

struct Problem{
    LL s;
    vector<LL> dig;
    Problem(LL s):s(s){};

    long long modpow(long long a, long long n,long long mod=MOD){
        long long i=1,ret=1,p=a;
        while(i<=n){
            if(i&n) ret=(ret*p)%mod;
            i=(i<<1);
            p=(p*p)%mod;
        }
        return ret;
    }
    LL calc(LL dl, LL dr, LL sum){
        //calculates the number of possible l, such that len(l)=dl,len(r)=dr.
        for(LL i=dl+1; i<dr; ++i){
            sum-=dig[i-1]*9*i;
        }
        LL g = __gcd(dl,dr);
        if(sum<0 or sum%g!=0)return 0;
        LL lb =1,ub = 9*dig[dl-1];
        while((sum-lb*dl)%dr)lb++;
        while((sum-ub*dl)%dr)ub--;
        if((sum-ub*dl)/dr<1){
            LL diff =1- (sum-ub*dl)/dr;
            diff = (diff+(dl/g)-1)/(dl/g)*(dr/g);
            ub-=diff;
        }
        if((sum-lb*dl)/dr>9*dig[dr-1]){
            LL diff = (sum-lb*dl)/dr-9*dig[dr-1];
            diff = (diff+(dl/g)-1)/(dl/g)*(dr/g);
            lb+=diff;
        }
        return max((ub-lb)/(dr/g)+1,0ll);
    }
    void solve(){
        for(LL i=0,j=1; i<10; ++i,j*=10){
            dig.push_back(j);
        }
        LL ans =0;
        for(int i=1; i<=10; ++i){
            for(int j=i+1; j<=10; ++j){
                ans+=calc(i,j,s);
            }
        }
        ans%=MOD;
        for(int i=1; i<=10; ++i){
            if(s%i==0){
                ans+=max(0ll,9*dig[i-1]-s/i+1);
            }
        }
        ans%=MOD;
        vector<LL> divisors;
        for(int i=1; i*i<=s; ++i){
            if(s%i==0){
                divisors.push_back(i);
                divisors.push_back(s/i);
            }
        }
        sort(divisors.begin(),divisors.end());
        divisors.erase(unique(divisors.begin(),divisors.end()),divisors.end());
        LL ub = (s-1)/10;
        ans+=ub;
        for(auto i :divisors){
            if(i>ub)break;
            int k = s/i;
            ans+= modpow(10,k-1)*9-i;
            ans%=MOD;
            ans=(ans+MOD)%MOD;
        }
        cout << ans << "\n";
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long s=0;
    std::cin >> s;
    Solver::Problem p(s);
    p.solve();
    return 0;
}

