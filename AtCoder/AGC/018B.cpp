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
    int n,m;
    vector<vector<int>> p;
    Problem(LL n, LL m):n(n),m(m),p (n,vector<int>(m)){};
    bool check(int x){
        vector<int> rank(n),cnt(m),eliminated(m);
        for(int i=0; i<n; ++i){
            cnt[p[i][0]]++;
        }
        while(*max_element(cnt.begin(),cnt.end())>x){
            vector<int> to_delete;
            for(int i=0; i<m; ++i){
                if(cnt[i]>x)to_delete.push_back(i);
            }
            for(auto && i:to_delete){
                eliminated[i]=1;
                cnt[i]=0;
            }
            for(int i=0; i<n; ++i){
                if(eliminated[p[i][rank[i]]]){
                    for(int j=rank[i]; j<m; ++j){
                        if(!eliminated[p[i][j]]){
                            rank[i]=j;
                            cnt[p[i][j]]++;
                            break;
                        }
                        if(j==m-1)return false;
                    }
                }
            }
        }
        return true;
    }
    void solve(){
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin >> p[i][j];
                p[i][j]--;
            }
        }
        int lb  = 0, ub = 300;
        while(abs(lb-ub)>1){
            int mid = (lb + ub)/2;
            if(check(mid)){
                ub = mid;
            }else{
                lb = mid;
            }
        }
        cout << ub <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,m;
    cin >> n >> m;
    Problem p(n,m);
    p.solve();
    return 0;
}

