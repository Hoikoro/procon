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

void myrot(vector<int> &a){
    auto it=a.end()-1;
    REPN(i,2,a.size()-1){
        if(*(a.end()-i)<*it or (it==a.end()-i+1 and *it==*(a.end()-i))) it=a.end()-i;
    }
    rotate(a.begin(),it,a.end());
    if(a[0]==a[2] && a[1]>a[3]) swap(a[1],a[3]);
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    map<vector<int>,int> a;
    LL ans=0;
    int n; cin >> n;
    vector<vector<int>> c(n,vector<int>(4));
    REP(i,n){
        cin >> c[i][0] >> c[i][1] >> c[i][2] >> c[i][3];
        myrot(c[i]);
        a[c[i]]++;
    }
    REP(i,n){
        FOR(j,i+1,n){
            a[c[i]]--;
            a[c[j]]--;
            vector<vector<int>> sid(4,vector<int>(4));
            REP(k,4){
                bool e[4]={};
                LL tmp=1;
                REP(l,4){
                    sid[l][0]=c[i][l];
                    sid[l][1]=c[j][(1-l+4)%4];
                    sid[l][2]=c[j][(-l+4)%4];
                    sid[l][3]=c[i][(l+1)%4];
                }
                REP(l,4) myrot(sid[l]);
                REP(l,4){
                    int cnt=a[sid[l]];
                    tmp*=cnt;
                    if(cnt>0){
                        a[sid[l]]--;
                        e[l]=true;
                    }
                    if(sid[l][0]==sid[l][3]) tmp*=4;
                    else if (sid[l][0]==sid[l][2] && sid[l][1]==sid[l][3]) tmp*=2;
                }
                REP(l,4) if(e[l]) a[sid[l]]++;
                ans+=tmp;
                /*if(tmp>0){
                    cout << i <<' '<< j << endl;
                    REP(l,4)cout << c[i][l]<< ' ';
                    REP(l,4)cout << c[j][l]<< ' ';
                    cout << tmp<<endl;
                }*/
                rotate(c[j].begin(),c[j].begin()+1,c[j].end());
            }
            a[c[i]]++;
            a[c[j]]++;
        }
        a[c[i]]--;

    }
    cout <<ans <<endl;

    return 0;
}
