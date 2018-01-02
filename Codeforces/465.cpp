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

vector<int> suffixArray(string &s){
    s+=' '; int l=s.size();
    vector<int> ret(l,-1),type(l); // L:0,S:1,LMS:2
    vector<int> cnt(130),press(130,0),buk(1,0),now;
    type[l-1]=1;
    cnt[s[l-1]-' ']++;
    for(int i=l-2;i>=0;--i){
        cnt[s[i]-' ']++;
        type[i]=(s[i]>s[i+1]?0:(s[i]<s[i+1]?1:type[i+1]));
    }
    for(int i=1; i<l;++i) if(type[i]==1 and type[i-1]==0) type[i]=2;
    int tmp=0;
    for(int i = 0;i<cnt.size();++i){
        if(0!=cnt[i]){
            press[i]=tmp++;
            if(i>0)buk.push_back(buk[tmp-2]+cnt[i]);
        }
    }
    now=buk;
    for(int i=0; i<l; ++i){
        if(type[i]==2){
            ret[now[press[s[i]-' ']]]=i;
            --now[press[s[i]-' ']];
        }
    }
    REP(j,2){
        now=buk;
        for(int i=0; i<l; ++i) if(type[ret[i]]!=2) ret[i]=-1;
        for(int i=0; i<l; ++i){
            if( ret[i]>0 and type[ret[i]-1]==0){
                ret[now[press[s[ret[i]-1]-' ']-1]+1]=ret[i]-1;
                ++now[press[s[ret[i]-1]-' ']-1];
            }
        }
        now=buk;
        for(int i=l-1; i>=0; --i){
            if(ret[i]>0 and type[ret[i]-1]!=0){
                ret[now[press[s[ret[i]-1]-' ']]]=ret[i]-1;
                --now[press[s[ret[i]-1]-' ']];
            }
        }
    }
    REP(i,l){cout << i << ' '<<ret[i]<< ' ' <<s.substr(ret[i])<<endl;}
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s,r;
    cin >> s;
    r=s;reverse(ALL(r));s=s+"/"+r;
    suffixArray(s);
    LL l=s.size();
    LL p[3]={999999937,MOD};
    LL b[3]={149853437,2345752};
    vector<VLL> rh(l+2,VLL(3)), revh(l+2,VLL(3));
    vector<VLL> power(l+2,VLL(3));
    REP(i,3) power[0][i]=1;
    FOR(i,1,l+1){
        REP(j,2){
            rh[i][j]=(rh[i-1][j]*b[j]+(s[i-1]-' '))%p[j];
            revh[i][j]=(revh[i-1][j]*b[j]+(s[l-i]-' '))%p[j];
            power[i][j]=power[i-1][j]*b[j]%p[j];
        }
    }



    return 0;
}
