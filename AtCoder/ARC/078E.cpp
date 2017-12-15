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
    long long pow_(long long a, long long n){
        long long i=1,ret=1,p=a;
        while(i<=n){
            if(i&n) ret*=p;
            i=(i<<1);
            p*=p;
        }
        return ret;
    }
    void solve(){
        vector<LL> ans,q;
        for(LL i=0,j=1; i<=9; ++i,++j){
            char tmp;
            cout << "? " << j <<"\n";
            q.push_back(j);
            cout <<flush;
            cin >> tmp;
            ans.push_back(tmp=='Y'?1:0);
            j=j*10-1;
            cout << "? " << j <<"\n";
            q.push_back(j);
            cout <<flush;
            cin >> tmp;
            ans.push_back(tmp=='Y'?1:0);
        }
        DBG(ans,q)
        int dig=0;
        if(ans[18]){
            LL ret=1e9;
            for(int i=8; i>=0; --i){
                if(ans[2*i+1]){
                    ret/=10;
                }else{
                    break;
                }
            }
            cout << "! " << ret <<"\n";
        }else{
            for(int i=8; i>=0; --i){
                if(ans[2*i]){
                    dig=i+1;
                    break;
                }
            }
            LL ub=pow_(10,dig)-1,lb=pow_(10,dig-1);
            while(ub-lb>1){
                LL mid=(ub+lb)/2;
                if(check(mid*10)) ub = mid;
                else lb=mid;
            }
            cout << "! " <<ub <<"\n";
        }

    }
    bool check(LL mid){
        cout << "? "<<mid <<"\n";
        cout << flush;
        char tmp;
        cin >> tmp;
        return tmp=='Y';
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Problem p;
    p.solve();
    return 0;
}

