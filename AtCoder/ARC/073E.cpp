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
    int n;
    vector<vector<LL>> v;
    vector<pair<LL,LL>> x;
    Problem(LL n):n(n),v (n,vector<LL>(2)),x(n){};

    void solve(){
        pair<int,int> argmax,argmin;
        LL maxi=0, mini=LINF;
        for(int i=0; i<n; ++i){
            for(int j=0; j<2; ++j){
                cin >> v[i][j];
                if(v[i][j]<mini)argmin={i,j},mini=v[i][j];
                if(v[i][j]>maxi)argmax={i,j},maxi=v[i][j];
            }
            x[i].first=max(v[i][0],v[i][1]);
            x[i].second=min(v[i][0],v[i][1]);
        }
        sort(x.begin(),x.end(),[](pair<LL,LL>&a, pair<LL,LL>&b){return a.second>b.second or (a.second==b.second and a.first>b.first);});
        multiset<LL> m;
        vector<pair<int,pair<int,int>>> intervals;
        for(int i=0; i<n; ++i){
            m.insert(x[i].first);
        }
        for(int i=0,ok=0; i<n-1; ++i){
            m.insert(x[i].second);
            m.erase(m.lower_bound(x[i].first));
            if(x[i].first==maxi)ok=1;
            if(ok)intervals.push_back({*m.rbegin()-*m.begin(),{*m.rbegin(),*m.begin()}});
        }
        sort(intervals.begin(),intervals.end());
        LL ans = LINF;
        //最大と最小を両方赤で塗る
        if(argmax.first!=argmin.first){
            //2つ青いボールが決まっている
            LL lb = min(v[argmax.first][!argmax.second],v[argmin.first][!argmin.second]);
            LL ub = max(v[argmax.first][!argmax.second],v[argmin.first][!argmin.second]);
            for(auto && i :intervals){
                if(i.second.first>=ub and i.second.second<=lb){
                    ans = min(ans,(maxi-mini)*(i.second.first-i.second.second));
                    break;
                }
            }
        }else{
            //最大と最小が同じ箱に入っていたら無理
        }
        //大きい方を赤、小さい方を青
        LL min_red = LINF, max_blue = 0;
        for(int i=0; i<n; ++i){
            min_red = min(min_red,max(v[i][0],v[i][1]));
            max_blue = max(max_blue,min(v[i][0],v[i][1]));
        }
        ans = min(ans, (maxi-min_red)*(max_blue-mini));
        cout << ans << "\n";
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

