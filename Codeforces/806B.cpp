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
const vector<int> pow2={1,2,4,8,16,32};
struct Problem{
    int n;
    vector<int> v,p;
    vector<int> cnt;
    Problem(LL n):n(n),v(5),p(5),cnt(5){};
    int score(int a){
        return a==-1?0:(250-a);
    }
    int tot_score(vector<int> &a, vector<int> &c){
        int ret=0;
        for(int i=0; i<5; ++i){
            ret+=a[i]*c[i];
        }
        return ret;
    }
    void solve(){
        for(int i=0; i<5; ++i){
            int tmp;
            cin >> tmp;
            if(tmp>=0)cnt[i]++;
            v[i]=score(tmp);
        }
        for(int i=0; i<5; ++i){
            int tmp;
            cin >> tmp;
            if(tmp>=0)cnt[i]++;
            p[i]=score(tmp);
        }
        for(int i=0; i<n-2; ++i){
            for(int j=0; j<5; ++j){
                int tmp;
                cin >> tmp;
                if(tmp>=0)cnt[j]++;
            }
        }
        DBG(cnt)
        vector<int> coeff(5);
        int ans=INF;
        for(int i=0; i<7776; ++i){
            for(int j=0,k=i; j<5; ++j){
                coeff[j]=(k%6)+1;
                k/=6;
            }
            int sv=tot_score(v,coeff);
            int sp=tot_score(p,coeff);
            if(sv<=sp)continue;
            DBG(sv,sp,coeff)
            for(int j=0; j<120*35; ++j){
                bool f=false;
                for(int k=0; k<5; ++k){
                    int lb,ub;
                    if(coeff[k]==1){
                        lb=(n+j)/pow2[1]+1;
                        ub=n+j;
                    }else if(coeff[k]==6){
                        lb=0;
                        ub=(n+j)/pow2[5];
                    }else{
                        lb=(n+j)/pow2[coeff[k]]+1;
                        ub=(n+j)/pow2[coeff[k]-1];
                    }
                    if(cnt[k]>ub or lb-cnt[k]>j or (v[k]==0 and lb-cnt[k]>0)){
                        f=true;
                        break;
                    }
                }
                if(f)continue;
                ans=min(ans,j);
            }
            DBG(ans)
        }
        if(ans==INF)cout << -1 <<"\n";
        else cout << ans <<"\n";
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

