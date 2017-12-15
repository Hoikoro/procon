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
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;
long long modpow(long long a, long long n){
    if(n==0) return 1;
    long long re=modpow((a*a)%MOD,n/2)%MOD;
    if(n%2==1) re= (re*a)%MOD;
    return re;
}
LL dp[3003][3003];
inline LL inv(LL a, LL b){return a*modpow(b,MOD-2)%MOD;}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    int cnt[3003]={},l[3003]={},u[3003]={};
    cin >> n >> m;
    string s;
    cin >> s;

    cnt[1]=(s[0]=='1'?1:0);
    FOR(i,2,n+1){
        cnt[i]=cnt[i-1]+(s[i-1]=='1'?1:0);
    }
    FOR(i,0,n+1)l[i]=u[i]=cnt[i];

    vector<PI> q;
    q.push_back({0,0});
    REP(i,m){
        int a,b;
        cin >> a>>b;
        q.push_back({a,b});
    }

    for(auto it= q.begin()+1;it<q.end();){
        if(it->second<=(it-1)->second){
            it=q.erase(it);
        }else{
            it++;
        }
    }
    for(auto it= q.begin();it<q.end()-1;){
        if(it->first==(it+1)->first){
            it=q.erase(it);
        }else{
            it++;
        }
    }

    q.insert(q.begin(),{0,0});
    FOR(i,1,q.size()){
        int f=cnt[q[i].second]-l[q[i].first-1];
        FOR(j,q[i].first,q[i].second+1){
            l[j]=l[q[i].first-1]+max(0,f-q[i].second+j);
            u[j]=min(cnt[q[i].second],u[q[i].first-1]+j-q[i].first+1);
        }
    }
    dp[0][0]=1;
    FOR(i,1,n+1){
        FOR(j,l[i],u[i]+1){
            dp[i][j]=(dp[i-1][j]+(j==0?0:dp[i-1][j-1]))%MOD;
            //cout << i << j << dp[i][j]<<endl;
        }
    }
    cout << dp[n][cnt[n]]<<endl;

    return 0;
}
