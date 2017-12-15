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
#define DBG(a) cerr<<#a<<' '<<(a)<<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;
LL ans;
LL r;
struct LLI {
    LL x,y;
    int i;
    LLI(LL a,LL b,int c){x=a;y=b;i=c;}
    LLI(){x=y=i=0;}
};
vector<LLI> cx,cy;
VLL sum, dif;
set<pair<pair<LL,LL>,int>> setx,sety;
inline bool compx(LLI a ,LLI b){
    return a.x<b.x  or(a.x== b.x and a.y<b.y);
}
inline bool compy(LLI a ,LLI b){
    return a.y<b.y or(a.y== b.y and a.x<b.x);
}


void bfs(int s){
    queue<int> Q;
    setx.erase(setx.lower_bound(MP(MP(sum[s],dif[s]),s)));
    sety.erase(sety.lower_bound(MP(MP(dif[s],sum[s]),s)));
    Q.push(s);
    while(!Q.empty()){
        s=Q.front();Q.pop();
        LL a[4]={sum[s]+r,sum[s]-r,dif[s]+r,dif[s]-r};
        REP(i,4){
            vector<LLI>::iterator be,en;
            if(i<2){
                be=lower_bound(ALL(cx),LLI(a[i],dif[s]-r,0),compx);
                en=lower_bound(ALL(cx),LLI(a[i],dif[s]+r+1,0),compx);
            }else{
                be=lower_bound(ALL(cy),LLI(sum[s]-r+1,a[i],0),compy);
                en=lower_bound(ALL(cy),LLI(sum[s]+r,a[i],0),compy);
            }
            ans+=en-be;
            //DBG(ans)
            if(i<2){
                auto next=setx.lower_bound(MP(MP(be->x,be->y),0));
                auto e=setx.lower_bound(MP(MP(en->x,en->y),0));
                while(next!=e){
                    Q.push(next->second);
                    sety.erase(sety.lower_bound(MP(MP(next->FI.SE,next->FI.FI),0)));
                    next=setx.erase(next);
                }
            }else{
                auto next=sety.lower_bound(MP(MP(be->y,be->x),0));
                auto e=sety.lower_bound(MP(MP(en->y,en->x),0));
                while(next!=e){
                    Q.push(next->second);
                    setx.erase(setx.lower_bound(MP(MP(next->FI.SE,next->FI.FI),0)));
                    next=sety.erase(next);
                }
            }
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin >> n>>a >>b;
    a--;b--;
    cx.resize(n);cy.resize(n);sum.resize(n);dif.resize(n);
    REP(i,n){
        LL tmp,tmp2;
        cin >>tmp>>tmp2;
        sum[i]=tmp+tmp2;dif[i]=tmp-tmp2;
        cx[i]={sum[i],dif[i],i};
        cy[i]={sum[i],dif[i],i};
        setx.insert(MP(MP(sum[i],dif[i]),i));
        sety.insert(MP(MP(dif[i],sum[i]),i));
    }
    cx.push_back(LLI(LINF,LINF,n));
    cy.push_back(LLI(LINF,LINF,n));
    sort(ALL(cx),compx);
    sort(ALL(cy),compy);
    setx.insert(MP(MP(LINF,LINF),n));
    sety.insert(MP(MP(LINF,LINF),n));
    r=max(abs(sum[a]-sum[b]),abs(dif[a]-dif[b]));
    bfs(a);
    cout << ans/2 << endl;

    return 0;
}
