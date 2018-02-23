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
    int h,w;
    vector<vector<char>> p,r,b;
    Problem(LL h, LL w):h(h),w(w),p (h,vector<char>(w)), r (h,vector<char>(w,'.')), b (h,vector<char>(w,'.')){};

    void solve(){
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                if(i==0)r[i][j]='#';
                else if(i==h-1)b[i][j]='#';
                else if(j%2==0)r[i][j]='#';
                else b[i][j]='#';
                cin >> p[i][j];
                if(p[i][j]=='#')r[i][j]=b[i][j]='#';
            }
        }
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cout << r[i][j];
            }
            cout <<"\n";
        }
        cout <<"\n";
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cout << b[i][j];
            }
            cout <<"\n";
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long h,w;
    cin >> h >> w;
    Problem p(h,w);
    p.solve();
    return 0;
}

