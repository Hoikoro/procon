#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;
//emplace_back next_permutation tie get

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define OUT(a) cout<<(a)<<endl;

int dat[22][22]={},n,m;
void swapcol(int a,int b){
    REP(i,n){
        swap(dat[i][a],dat[i][b]);
    }
    return;
}

bool check(){
    REP(i,n){
        int tmp=0;
        REP(j,m){
            if(dat[i][j]!=j+1) tmp++;
        }
        if(tmp>2) return false;
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    bool f=true;
    int s=-1;
    cin >> n >> m;
    vector<vector<int>> dif(n);


    REP(i,n){
        REP(j,m){
            cin >> dat[i][j];
        }
    }
    REP(i,n){
        REP(j,m){
            if(dat[i][j]!=j+1){
                dif[i].push_back(j);
            }
        }
    }
    REP(i,n){
        if(dif[i].size()>4) {
            f=false;
            break;
        }
        if(dif[i].size()>2){
            s=i;
            break;
        }
    }
    //OUT(s)
    if(s>=0){
        f=false;
        do{
            //OUT(dif[1][0])
            //OUT(dif[1][1])
            swapcol(dif[s][0],dif[s][1]);
            if(check()){
                f=true;
                break;
            }
            swapcol(dif[s][0],dif[s][1]);
        }while(next_permutation(dif[s].begin(),dif[s].end()));
    }



    if(f) cout << "YES" <<endl;
    else cout << "NO" <<endl;

    return 0;
}
