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
    int h;
    vector<int> a;
    Problem(LL h):h(h),a(h+1){};

    void solve(){
        for(int i=0; i<h+1; ++i){
            cin >> a[i];
        }
        int hh;
        for(int i=0; i<h; ++i){
            if(a[i]>1 and a[i+1]>1){
                hh=i+1;
                break;
            }
            if(i==h-1){
                cout << "perfect" <<"\n";
                return;
            }
        }
        cout << "ambiguous" <<"\n";
        for(int i=0; i<=h; ++i){
            cout << i<<' ';
        }
        for(int i=0; i<=h; ++i){
            for(int j=0; j<a[i]-1; ++j){
                cout << i <<' ';
            }
        }
        cout <<"\n";
        int cnt =0;
        for(int i=0; i<=h; ++i){
            cout << i<<' ';
            cnt ++;
        }
        for(int i=0; i<=h; ++i){
            if(i==hh){
                cout << cnt <<' ';
                for(int j=0; j<a[i]-2; ++j){
                    cout << i <<' ';
                }
            }else{
                for(int j=0; j<a[i]-1; ++j){
                    cout << i <<' ';
                    cnt ++;
                }
            }
        }
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

