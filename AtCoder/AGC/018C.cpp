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
    LL x,y,z,ans;
    vector<pair<LL,LL>> bc;
    vector<LL> diff;
    Problem(LL x,LL y, LL z):x(x),y(y),z(z),ans(0),diff(y+1){};

    void solve(){
        for(int i=0; i<x+y+z; ++i){
            LL a,bb,cc;
            cin >> a >> bb >> cc;
            ans+=a;
            bc.emplace_back(bb-a,cc-a);
        }
        sort(bc.begin(),bc.end(),[&](pair<LL,LL> &a, pair<LL,LL>&b){return a.second>b.second or(a.second==b.second and a.first<b.first);});

        priority_queue<LL> diffs;
        for(int i=0; i<z; ++i){
            ans+=bc[i].second;
            diffs.push(bc[i].first-bc[i].second);
        }
        for(int i=1; i<=y; ++i){
            diff[i]=diff[i-1]+diffs.top();
            diffs.pop();
            diffs.push(bc[z-1+i].first-bc[z-1+i].second);
        }
        DBG(bc,diff)

        priority_queue<LL>bs;
        for(int i=y+z-1; i<x+y+z; ++i){
            bs.push(bc[i].first);
        }
        LL tmp = diff[y];
        for(int i=z; i<y+z; ++i){
            tmp+=bc[i].second;
        }
        LL maxi =tmp;
        DBG(ans,maxi,bs.size())
        for(int i=y-1; i>=0; --i){
            tmp-=bc[z+i].second;
            tmp+=diff[i]-diff[i+1];
            tmp+=bs.top();
            DBG(i,tmp,bs.top())
            bs.pop();
            maxi=max(maxi,tmp);
            bs.push(bc[z+i-1].first);
        }
        cout << ans+maxi <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long x,y,z;
    cin >> x >> y >> z;

    Problem p(x,y,z);
    p.solve();
    return 0;
}

