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
    vector<LL> a;
    Problem(LL n):n(n),a(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        LL cnt[2]={},sum[2]={};
        //plus
        if(a[0]<=0){
            cnt[0]=1-a[0];
            sum[0]=1;
        }else{
            sum[0]=a[0];
        }
        for(int i=1; i<n; ++i){
            LL s= sum[0]+a[i];
            if(sum[0]< 0 and s<=0){
                cnt[0]+=1-s;
                sum[0]=1;
            }else if (sum[0]>0 and s>=0){
                cnt[0]+=s+1;
                sum[0]=-1;
            }else{
                sum[0]+=a[i];
            }
            DBG(sum[0],cnt[0])
        }
        //minus
        if(a[0]>=0){
            cnt[1]=a[0]+1;
            sum[1]=-1;
        }else{
            sum[1]=a[0];
        }
        for(int i=1; i<n; ++i){
            LL s= sum[1]+a[i];
            if(sum[1]< 0 and s<=0){
                cnt[1]+=1-s;
                sum[1]=1;
            }else if (sum[1]>0 and s>=0){
                cnt[1]+=s+1;
                sum[1]=-1;
            }else{
                sum[1]+=a[i];
            }
            DBG(sum[1],cnt[1])
        }
        DBG(cnt[0],cnt[1])
        cout << min<LL>(cnt[0],cnt[1]) <<"\n";
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

