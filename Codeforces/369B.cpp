#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n)-1)
#define FOR(i,a,b) for(int (i)=(a); (i)<=(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n;
    LL m[505][505]={};
    vector<LL> emp;
    cin >> n;
    if(n==1){
        cout << 1 <<endl;
        return 0;
    }
    vector<LL> line(2*n+2);
    REP(i,n){
        REP(j,n){
            cin >> m[i][j];
        }
    }
    REP(i,n){
        REP(j,n){
            line[i]+=m[i][j];
            if(m[i][j]==0){
                emp.push_back(i);
            }
        }
    }
    REP(i,n){
        REP(j,n){
            line[n+i]+=m[j][i];
            if(m[j][i]==0){
                emp.push_back(n+i);
            }
        }
    }
    REP(i,n){
        line[2*n]+=m[i][i];
        if(m[i][i]==0){
            emp.push_back(2*n);
        }
    }
    REP(i,n){
        line[2*n+1]+=m[i][n-i-1];
        if(m[i][n-i-1]==0){
            emp.push_back(2*n+1);
        }
    }
    /*for(auto x:line){
        cout  << x <<endl;
    }
    for(auto x : emp){
        cout << x <<endl;
    }*/
    LL tot=line[emp[0]];
    for(auto x: emp){
        if(line[x]!=tot){
            cout << -1 << endl;
            return 0;
        }
    }
    REP(i,emp.size()){
        line.erase(line.begin()+emp[i]-i);
    }
    LL tot2=line[0];
    for(auto x : line){
        if(x!=tot2){
            cout << -1 << endl;
            return 0;
        }
    }
    if(tot2-tot>0){
        cout << tot2-tot <<endl;
    }else{
        cout << -1 << endl;
    }


    return 0;
}
