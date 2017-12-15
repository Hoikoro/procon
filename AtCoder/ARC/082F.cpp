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
    LL x,k,q;
    vector<LL> r,t,a;
    vector<vector<LL>> s;
    void solve(){
        cin >> x >> k;
        r.push_back(0);
        for(int i=0; i<k; ++i){
            int tmp;
            cin>> tmp;
            r.push_back(tmp);
        }
        cin >> q;
        for(int i=0; i<q; ++i){
            int tt,mm;
            cin>> tt >> mm;
            t.push_back(tt);
            a.push_back(mm);
        }
        s= vector<vector<LL>> (k+1,vector<LL>(4));
        s[0]={0,0,x,x};
        for(int i=1; i<=k; ++i){ //s[i]
            LL dr= r[i]-r[i-1];
            DBG(dr)
            if(i%2!=0){ //decreasing
                s[i]={max(s[i-1][0]-dr,0ll),max(s[i-1][1],dr-(s[i-1][0]-s[i-1][1])),
                    s[i-1][2],max(s[i-1][3]-dr,0ll)};
            }else{ //increasing
                s[i]={min(s[i-1][0]+dr,x),s[i-1][1],
                    min(s[i-1][2],x-dr-(s[i-1][3]-s[i-1][2])),min(s[i-1][3]+dr,x)};
            }
            if(s[i][2]<=s[i][1]){
                assert(s[i][0]==s[i][3]);
                s[i][2]=0;
                s[i][1]=x;
            }
        }
        DBG(s)
        for(int i=0; i<q; ++i){
            LL it = upper_bound(r.begin(),r.end(),t[i])-r.begin();
            it--;
            DBG(i,it)
            LL prev;
            if(a[i]<=s[it][1]) prev = s[it][0];
            else if(a[i]>=s[it][2])prev = s[it][3];
            else prev = s[it][0] + (a[i]-s[it][1]);
            DBG(prev)
            if(it%2==0){ //dec
                cout << max(0ll, prev-(t[i]-r[it])) <<"\n";
            }else{ //inc
                cout << min(x,prev+(t[i]-r[it]))<<"\n";
            }
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    Problem p;
    p.solve();
    return 0;
}

