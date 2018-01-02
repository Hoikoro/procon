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
typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;
//StronglyC ConeectC Components

struct Edge{
    int from,to;
    Edge(int from,int to)
        : from(from),to(to){};
    Edge(){Edge(0,0);}
};
typedef vector<vector<Edge>> Graph;

struct stronglyConnectedComponents{
    vector<int> scrank,vis,po;
    stronglyConnectedComponents(int n){
        scrank=vector<int>(n); vis=vector<int>(n);
    }
    private:
    void dfs(int a,Graph &g){
        vis[a]=1;
        for(int i=0; i<g[a].size(); ++i){
            if(!vis[g[a][i].to]) dfs(g[a][i].to,g);
        }
        po.push_back(a);
    }
    void rdfs(int a, int k, Graph &rg){
        scrank[a]=k;
        vis[a]=1;
        for(int i=0; i<rg[a].size(); ++i){
            if(!vis[rg[a][i].to]) rdfs(rg[a][i].to,k,rg);
        }
    }
    public:
    void calc(Graph &g, Graph& rg){
        for(int i=0; i<g.size(); ++i){
            if(!vis[i]) dfs(i,g);
        }
        fill(ALL(vis),0);
        int c=0;
        for(int i=rg.size()-1; i>=0; --i){
            if(!vis[po[i]]) rdfs(po[i],c++,rg);
        }
    }
};



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n>52){cout << "Impossible" << endl; return 0;}
    string s[52]={};
    vector<tuple<string,int,int>> v;
    REP(i,n){
        cin >> s[i];
        v.push_back(make_tuple(s[i].substr(0,1),2*i,2*i+1));
        v.push_back(make_tuple(s[i].substr(1,2),2*i,2*i+1));
        v.push_back(make_tuple(s[i].substr(0,2),2*i+1,2*i));
        v.push_back(make_tuple(s[i].substr(2,1),2*i+1,2*i));
    }
    sort(ALL(v));
    Graph g(n*2),rev(n*2);
    stronglyConnectedComponents scc(n*2);
    REP(i,4*n){
        FOR(j,i+1,4*n){
            if(get<0>(v[i])==get<0>(v[j])){
                g[get<1>(v[i])].push_back(Edge(get<1>(v[i]),get<2>(v[j])));
                rev[get<2>(v[j])].push_back(Edge(get<2>(v[j]),get<1>(v[i])));
                g[get<1>(v[j])].push_back(Edge(get<1>(v[j]),get<2>(v[i])));
                rev[get<2>(v[i])].push_back(Edge(get<2>(v[i]),get<1>(v[j])));
            }
        }
    }
    scc.calc(g,rev);
    REP(i,n) {
        if(scc.scrank[2*i]==scc.scrank[2*i+1]){
            cout << "Impossible"<<endl;
            return 0;
        }
    }
    REP(i,n){
        if(scc.scrank[2*i]>scc.scrank[2*i+1]) cout<< s[i].substr(0,1)<<' '<<s[i].substr(1)<<endl;
        else cout<< s[i].substr(0,2)<<' '<<s[i].substr(2)<<endl;
    }

    return 0;
}
