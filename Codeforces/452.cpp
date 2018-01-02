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
#include <random>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define dump(a) cerr<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,ans=0;
    cin >> n >> m;
    vector<vector<PI>> id(n*n*m+1);
    vector<vector<vector<int>>> card(m,vector<vector<int>>(2*n+2));
    REP(i,m){
        int tmp;
        REP(j,n){
            REP(k,n){
                cin >> tmp;
                card[i][j].push_back(tmp);
                card[i][n+k].push_back(tmp);
                id[tmp].emplace_back(i,j);
                id[tmp].emplace_back(i,n+k);
                if(j==k){
                    card[i][2*n].push_back(tmp);
                    id[tmp].emplace_back(i,2*n);
                }
                if(j+k==n-1){
                    card[i][2*n+1].push_back(tmp);
                    id[tmp].emplace_back(i,2*n+1);
                }
                int loop=2+(j==k?1:0)+(j+k==n-1?1:0),size=id[tmp].size();
                for(int l=size-loop;l<size;++l){
                    for(int h=0;h<size-loop;++h){
                        int cnt=1;
                        for(int g=0;;g++){
                            int a=card[i][id[tmp][l].SE][g];
                            if(a==tmp)break;
                            vector<int> &v=card[id[tmp][h].FI][id[tmp][h].SE];
                            if(*lower_bound(ALL(v),a)==a)cnt++;
                        }
                        //if(ans<cnt) {dump(tmp)dump(loop)}
                        ans=max(ans,cnt);
                    }
                }
            }
        }
        REP(j,2*n+2)sort(ALL(card[i][j]));
    }

    cout << 2*n-1-ans <<endl;


    return 0;
}
