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
    LL n;
    vector<LL> p;
    Problem(LL n):n(n),p(n){};

    void solve(){
        LL ans=0,minsum=LINF,sum=0;
        for(int i=0; i<n; ++i){
            cin >> p[i];
            p[i]--;
        }
        multiset<LL> s;
        for(int i=0; i<n; ++i){
            if(p[i]-i>0)s.insert(p[i]-i);
            sum+=abs(p[i]-i);
        }
        minsum=sum;
        DBG(minsum,s)
        for(int i=1; i<n; ++i){
            LL cnt;
            if(p[n-i]-(n-1)>0)cnt=(int)s.size()-1;
            else cnt=(int)s.size();
            sum+=n-1-2*cnt;
            DBG(sum,cnt)
            sum=sum-abs(p[n-i]-(n-1))+abs(p[n-i]);

            s.erase(i);
            if(p[n-i]>0)s.insert(p[n-i]+i);
            DBG(s)
            DBG(i,sum)
            if(sum<minsum){
                minsum=sum;
                ans=i;
            }
        }

        cout << minsum << ' '<<ans <<"\n";


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

