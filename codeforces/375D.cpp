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
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;
int dx[4]={1,0,-1,0} ,dy[4]={0,1,0,-1},visited[55][55]={},kk,ans,cnt;
vector<pair<int,pair<int,int>>> del;
bool r=true;
int n,m,k;
char dat[55][55];
int  dfs(int a, int b,bool c){
    if( a==0 or b==0 or a==n-1 or b==m-1){
        r=false;
        return 0;
    }
    if(visited[a][b])return 0;
    visited[a][b]=1;
    int ret=0;
    if(dat[a][b]=='.'){
        ret=1;
        REP(i,4){
            if(dat[a+dx[i]][b+dy[i]]=='.') {
                //cnt++;
                ret+=dfs(a+dx[i],b+dy[i],c);
            }
        }
        if(c) dat[a][b]='*';
        //ret++;
    }
    //if(!r)cnt=0;
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);


    cin >> n >> m>>k;
    REP(i,n){
        REP(j,m){
            cin>>dat[i][j];

        }
    }

    REP(i,n){
        REP(j,m){
            cnt=0;
            r=true;
            cnt=dfs(i,j,false);
            if(r and cnt>0){
                del.push_back(make_pair(cnt,make_pair(i,j)));
                //cout << cnt << ' ' <<i << ' ' <<j <<endl;
                kk++;
            }
        }
    }
    //OUT(kk)
    sort(del.begin(),del.end());

    REP(i,55)REP(j,55) visited[i][j]=0;
    REP(i,kk-k){
        int f=del.front().first;
        int sf=del.front().second.first;
        int ss=del.front().second.second;
        del.erase(del.begin());
        ans+=f;
        dfs(sf,ss,true);
    }

    cout << ans << endl;
    REP(i,n){
        REP(j,m){
            cout << dat[i][j];
        }
        cout << endl;
    }


    return 0;
}
