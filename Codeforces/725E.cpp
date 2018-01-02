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
#include <chrono>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define OUT(a) cout<<(a)<<endl;
#define ALL(v) (v).begin(), (v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=1ll<<62; const int INF=1ll<<30; const LL MOD=1E9+7;
bool search(int a,vector<int> &c){
    auto it=upper_bound(c.begin(),c.end(),a)-1;
    while(1){
        while(it!=c.begin() && *it>a) --it;
        a-=*it;
        it--;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    chrono::system_clock::time_point start,end;
    start=chrono::system_clock::now();

    int c,n,b[200020]={},tot=0;
    fill(b,b+200020,-2);
    cin >> c >> n;
    vector<int> coins(n+1),g;
    REP(i,n){
        cin >> coins[i+1];
    }
    sort(ALL(coins));
    b[0]=0;
    REPN(i,1,n){
        //OUT(i)
        tot=min(c,tot+coins[i]);
        for(int j=tot; j>=coins[i];--j){
            if(b[j-coins[i]]!=-2 && (b[j-coins[i]]==i-1 || coins[i-1]<coins[i])){
                b[j]=i;
            }else if(b[j-coins[i]]!=-2) break;
        }
        //REPN(i,1,c)cout << i <<' ' << b[i] <<endl;

    }
    REPN(i,1,c){
        if(b[i]==-2) g.PB(i);
    }

    int left=c,ans=INF;
    while(left!=0){
        OUT(left)
        auto it=upper_bound(ALL(g),left-coins[b[left]]-1);
        if(it!=g.begin()) {
            //OUT(left-*(it-1))
            ans=min(ans,left-*(it-1));
        }
        left-=coins[b[left]];
    }
    if(ans==INF)cout <<"Greed is good" <<endl;
    else cout << ans <<endl;

    end=chrono::system_clock::now();
    cout<<chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<<endl;
    return 0;
}
