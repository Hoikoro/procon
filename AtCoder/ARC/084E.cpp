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
    LL k,n;
    void solve(){
        cin >> k >> n;
        vector<LL> ans(n);
        if(k%2==0){
            ans[0]=k/2;
            for(int i=1; i<n; ++i){
                ans[i]=k;
            }
        }else{
            for(int i=0; i<n; ++i){
                ans[i]=(k+1)/2;
            }
            LL backstep = n/2;
            vector<LL> s(n);
            s[0]=1;
            LL dig = 1,diff=k;
            while(1){
                s[dig]=s[dig-1]+diff;
                if(s[dig]>backstep)break;
                diff*=k;
                dig++;
            }
            for(int i=dig-1; i>=0; --i){
                LL tmp = min(ans[n-1-i]-1,backstep/s[i]);
                ans[n-1-i]-=tmp;
                backstep-=tmp*s[i];
            }
            for(int i=0; i<backstep; ++i){
                if(ans.back()==1){
                    ans.pop_back();
                }else if((int)ans.size()<n){
                    ans.back()--;
                    while((int)ans.size()<n)ans.push_back(k);
                }else{
                    ans[n-1]--;
                }
            }
        }
        for(int i=0; i<ans.size(); ++i){
            cout << ans[i] <<' ';
        }
        cout <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Problem p;
    p.solve();
    return 0;
}

