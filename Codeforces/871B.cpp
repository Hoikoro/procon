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
    vector<int> ansb;
    Problem(LL n):n(n),ansb(n){};

    void solve(){
        if(__builtin_popcount(n)==1){
            vector<int> rep(n),q;
            vector<vector<int>> ansbv,c;
            for(int i=0; i<n; ++i){
                cout << "? 0 "<<i <<"\n";
                fflush(stdout);
                cin >> rep[i];
            }
            vector<int> kk;
            for(int i=0; i<n; ++i){ //p[]=i
                bool fin=true;
                for(int j=0; j<n; ++j){
                    ansb[j]=i^rep[j];
                    if(ansb[j]>=n){
                        fin=false;
                        break;
                    }
                }
                //DBG(ansb)
                if(ansb[i]==0){
                    q.push_back(i);
                    vector<int> tmp(n);
                    for(int j=0; j<n; ++j){
                        tmp[ansb[j]]=j;
                    }
                    ansbv.push_back(ansb);
                    c.push_back(tmp);
                    DBG(i)
                    DBG(tmp)
                    DBG(ansbv)
                }else{
                    kk.push_back(i);
                }
            }
            if((int)kk.size()==0){
                cout << "!" <<"\n";
                fflush(stdout);
                cout << n <<"\n";
                fflush(stdout);
                for(int i=0; i<n; ++i){
                    cout << ansbv[0][i] << (i!=n-1?" ":"\n");
                    fflush(stdout);
                }
            }else{
                DBG(ansbv)
                vector<int> ok((int)kk.size(),1);
                for(int i=0; i<(int)kk.size(); ++i){
                    cout << "? "<<kk[i]<<' ' <<kk[i]<<"\n";
                    fflush(stdout);
                    int ret;
                    cin >> ret;
                    for(int j=0; j<(int)kk.size(); ++j){
                        DBG(j)
                        if((ansbv[j][kk[i]]^c[j][kk[i]])!=ret)ok[j]=0;
                    }
                }
                cout << "!" <<"\n";
                fflush(stdout);
                cout << accumulate(ok.begin(),ok.end(),0)<<"\n";
                fflush(stdout);
                for(int i=0; i<(int)kk.size(); ++i){
                    if(ok[i]==1){
                        for(int j=0; j<n; ++j){
                            cout << c[i][j] << (i!=n-1?" ":"\n");
                            fflush(stdout);
                        }
                    }
                }

            }
        }else{
            vector<int> rep(n);
            for(int i=0; i<n; ++i){
                cout << "? 0 "<<i <<"\n";
                fflush(stdout);
                cin >> rep[i];
            }
            for(int i=0; i<n; ++i){ //p[0]=i
                bool fin=true;
                for(int j=0; j<n; ++j){
                    ansb[j]=i^rep[j];
                    if(ansb[j]>=n){
                        fin=false;
                        break;
                    }
                }
                if(fin)break;
            }
            cout << "!" <<"\n";
            fflush(stdout);
            cout << 1 <<"\n";
            fflush(stdout);
            vector<int> ansp(n);
            for(int i=0; i<n; ++i){
                ansp[ansb[i]] = i;
            }
            for(int i=0; i<n; ++i){
                cout << ansp[i] << (i!=n-1?" ":"\n");
                fflush(stdout);
            }
        }
    }
};

int main(){
    long long n=0;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

