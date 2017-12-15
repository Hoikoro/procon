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
    int r,c,n;
    vector<pair<int,int>> p;
    vector<int> pl;
    Problem(LL r, LL c, LL n):r(r),c(c),n(n){};
    int conv(int a, int b){
        if(a==0) return b;
        else if(b==c) return c+a;
        else if(a==r) return r+c+(c-b);
        else return r+2*c+(r-a);
    }
    void solve(){
        for(int i=0; i<n; ++i){
            int w,x,y,z,tmp=0;
            cin >> w >> x >> y >> z;
            if(w==0 or w == r or x==0 or x == c)tmp++;
            if(y==0 or y == r or z==0 or z == c)tmp++;
            if(tmp==2){
                p.emplace_back(conv(w,x),i);
                p.emplace_back(conv(y,z),i);
            }
        }
        sort(p.begin(),p.end());
        for(int i=0; i<p.size(); ++i){
            pl.push_back(p[i].second);
        }
        vector<int> s;
        for(int i=0; i<(int)pl.size(); ++i){
            if(!s.empty() and s.back() == pl[i])s.pop_back();
            else s.push_back(pl[i]);
        }
        if(!s.empty()) no();

        cout<<"YES"<<"\n";

    }

    void no(){cout << "NO"<<"\n"; exit(0);}
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long r,c,n=0;
    cin >> r >> c >> n;
    Problem p(r,c,n);
    p.solve();
    return 0;
}

