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

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,l[100010]={},r[100010]={},mmex=INF,ans[100010]={},cnt[100010]={};
    fill(ans,ans+100010,-1);
    vector<int> a;
    cin >> n >> m;
    vector<pair<int,int>> b(m);
    REP(i,m){
        cin >> b[i].FI>>b[i].SE;
        b[i].FI--;
        b[i].SE--;
        mmex=min(mmex,b[i].SE-b[i].FI+1);
    }
    sort(b.begin(),b.end());
    int t=0,p=0;
    REP(i,m){
        if((b[i].SE-b[i].FI+1)==mmex){
            p=max(p,b[i].FI);
            FOR(j,p,b[i].SE+1){
                ans[j]=t;
                cnt[j+1]=1;
                t=(t+1)%mmex;
                p++;
            }
        }
    }
    //REP(i,n-1)cout << ans[i] << ' ';
    //cout << ans[n-1] <<endl;
    REP(i,n) cnt[i+1]+=cnt[i];
    p=0;
    int q=0;
    REP(i,m){
        if((b[i].SE-b[i].FI+1)!=mmex){
            int y=cnt[b[i].FI];
            int z=cnt[b[i].SE+1];
            q=max(b[i].FI,p);
            FOR(j,q,b[i].SE+1){
                if(ans[j]==-1){
                    if(z-y>=mmex)break;
                    ans[j]=z%mmex;
                    p=j;
                    z=(z+1);
                }
            }
            p++;
        }
    }
    REP(i,n) if(ans[i]==-1)ans[i]=0;
    cout << mmex << endl;
    REP(i,n-1)cout << i%mmex << ' ';
    cout << (n-1)%mmex <<endl;

    return 0;
}
