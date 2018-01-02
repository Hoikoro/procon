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
double eps=1e-8;

int sweepout(vector<vector<double>> &t){
    double eps=1e-8;
    int dig=t.size(),n=t[0].size(),rank=0;
    for(int i=0;i<n;++i){
        int p=rank;
        while(abs(t[p][i])<eps){
            p++;
            if(p==dig) break;
        }
        if(p==dig) continue;
        t[rank].swap(t[p]);
        for(int j=rank+1;j<dig;++j){
            for(int k=i+1;k<n;++k){
                t[j][k]-=t[rank][k]*t[j][i]/t[rank][i];
            }
        }
        rank++;
        if(rank==min(n,dig))break;
    }
    return rank;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    LL a;
    const int dig=61;
    vector<vector<double>> t(dig,(vector<double>(n)));
    REP(i,n){
        cin >> a;
        REP(j,dig){
            t[j][i]=(a>>j)&1;
        }
    }
    //cout << (1ll<<sweepout(t) )<<endl;
    int ans=0;
    REP(i,n){
        int p=ans;
        while(abs(t[p][i])<eps){
            p++;
            if(p==dig) break;
        }
        if(p==dig) continue;
        t[ans].swap(t[p]);
        FOR(j,ans+1,dig){
            FOR(k,i+1,n){
                t[j][k]-=t[ans][k]*t[j][i]/t[ans][i];
            }
        }
        ans++;
        if(ans==min(n,dig))break;
    }
    cout << (1ll<<ans)<<endl;
    return 0;
}
