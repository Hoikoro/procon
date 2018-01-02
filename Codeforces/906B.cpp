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
    vector<deque<int>> p;
    Problem(LL n, LL m):n(n),m(m),p (2){};

    void solve(){
        bool swapped=false;
        vector<vector<int>> ss (m,vector<int>(n));
        if(n>m){
            swapped=true;
            for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                    ss[j][i]=i*m+j+1;
                }
            }
            DBG(ss)
            swap(n,m);
        }
        if(n==1 and m ==1){
            cout <<"YES"<<"\n";
            cout << 1 <<' ' << "\n";
        }else if(n==3 and m==3){
            /*vector<int> p(9);
            bool ok = false;
            for(int i=0; i<9; ++i){
                p[i]=i;
            }
            do{
                vector<vector<int>> pp (3,vector<int>(3));
                for(int i=0; i<3; ++i){
                    for(int j=0; j<3; ++j){
                        pp[i][j]=p[i*3+j];
                    }
                }
                DBG(pp)
                bool tmp = true;
                for(int i=0; i<3; ++i){
                    for(int j=0; j<3; ++j){
                        if(i<2){
                            pair<int,int> a,b;
                            a={pp[i][j]/3,pp[i][j]%3};
                            b={pp[i+1][j]/3,pp[i+1][j]%3};
                            if(abs(a.first-b.first)+abs(a.second-b.second)==1)tmp=false;
                        }
                        if(j<2){
                            pair<int,int> a,b;
                            a={pp[i][j]/3,pp[i][j]%3};
                            b={pp[i][j+1]/3,pp[i][j+1]%3};
                            if(abs(a.first-b.first)+abs(a.second-b.second)==1)tmp=false;
                        }
                    }
                }
                if(tmp){
                    ok=true;
                    break;
                }
            }while(next_permutation(p.begin(),p.end()));
            if(!ok){
                cout << "NO" <<"\n";
            }else{
                for(int i=0; i<3; ++i){
                    for(int j=0; j<3; ++j){
                        cout << p[i*3+j]+1 <<' ';
                    }
                    cout <<"\n";
                }
            }*/
            vector<int> q={1,3,4,5,7,6,9,2,8};
            cout << "YES" << "\n";
            for(int i=0; i<3; ++i){
                for(int j=0; j<3; ++j){
                    cout << q[i*3+j] <<' ';
                }
                cout <<"\n";
            }
        }else if(n<=3 and m<=3){
            cout <<"NO" <<"\n";
        }else{
            p[0]={3,1,4,2};
            for(int i=5; i<=m; ++i){
                if(i%2==1)p[0].push_front(i);
                else p[0].push_back(i);
            }
            if(m%2==0){
                for(int i=0; i<m; ++i){
                    p[1].push_back(p[0][m-1-i]);
                }
            }else{
                p[1]={3,1,4,2};
                for(int i=5; i<=m; ++i){
                    if(i%2==1)p[1].push_back(i);
                    else p[1].push_front(i);
                }
            }
            cout << "YES" << "\n";
            if(!swapped){
                DBG(n,m,p)
                for(int i=0; i<n; ++i){
                    for(int j=0; j<m; ++j){
                        cout << i*m+p[i%2][j] <<' ';
                    }
                    cout <<"\n";
                }
            }else{
                DBG(n,m,p)
                for(int i=0; i<m; ++i){
                    for(int j=0; j<n; ++j){
                        cout << ss[j][p[j%2][i]-1] <<' ';
                    }
                    cout <<"\n";
                }
            }
        }
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

