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

//make_tuple emplace_back next_permutation
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(...) string s999=#__VA_ARGS__;replace(ALL(s999),',',' ');stringstream ds999; ds999<<s999; debug(ds999,__VA_ARGS__);
inline void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<' '<<f<<' '; debug(ds,r...);}
#define ALL(v) (v).begin(),(v).end()
#define SI(v) (int)(v).size()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;
struct Edge{
    int from,to;
    Edge(int from,int to)
        : from(from),to(to) {};
};
typedef vector<vector<Edge>> Graph;
int k;

int defineDepth(Graph &T, vector<int> &p, vector<int> &dep,int root,int root2){
    int ret =0;
    queue<int> Q;
    Q.push(root);
    Q.push(root2);
    p[root]=root;
    p[root2]=root2;
    while(!Q.empty()){
        int nex=Q.front();
        Q.pop();
        for(auto &x: T[nex]){
            if(p[x.to]==-1){
                p[x.to]=x.from;
                Q.push(x.to);
                dep[x.to]=dep[x.from]+1;
                if(dep[x.to]>k/2) ++ret;
            }
        }
    }
    return ret;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> k;
    Graph t(n);
    REP(i,n-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        t[a].push_back(Edge(a,b));
        t[b].push_back(Edge(b,a));
    }
    int ans=INF;
    REP(i,n){
        REP(j,t[i].size()+1){
            vector<int> vis(n,-1),dep(n);
            if(k%2==0 and j==t[i].size()){
                ans=min(ans,defineDepth(t,vis,dep,i,i));
            }else if(k%2==1 and j<t[i].size() and i<t[i][j].to){
                ans=min(ans,defineDepth(t,vis,dep,i,t[i][j].to));
            }
            //DBG(i,j,ans)
        }
    }
    cout << ans <<endl;

    return 0;
}
