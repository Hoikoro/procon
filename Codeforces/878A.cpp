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
    vector<vector<int>> x;
    Problem(LL n):n(n),x (10,vector<int>(2)){};

    void solve(){
        for(int i=0; i<10; ++i){
            x[i][1]=1;
        }
        for(int i=0; i<n; ++i){
            char c; int a;
            cin >> c >> a;
            if(c=='|'){
                for(int j=0; j<10; ++j){
                    if((a>>j)&1){
                        x[j][0]=1;
                        x[j][1]=1;
                    }
                }
            }else if(c=='&'){
                for(int j=0; j<10; ++j){
                    if(((a>>j)&1)==0){
                        x[j][0]=0;
                        x[j][1]=0;
                    }
                }
            }else{
                for(int j=0; j<10; ++j){
                    if((a>>j)&1){
                        x[j][0]=(1-x[j][0]);
                        x[j][1]=(1-x[j][1]);
                    }
                }
            }
        }
        int ao=0,aa=1023,ax=0;
        for(int i=0; i<10; ++i){
            int tmp= x[i][0]+x[i][1]*2;
            if(tmp==0){
                aa-=(1<<i);
            }else if(tmp==1){
                ax+=(1<<i);
            }else if(tmp==3){
                ao+=(1<<i);
            }
        }
        cout << 3 <<"\n";
        cout << "| "<<ao <<"\n";
        cout << "& "<<aa <<"\n";
        cout << "^ "<<ax <<"\n";
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

