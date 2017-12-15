#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dbgsplit(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dbgsplit(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}
using LL = long long;
constexpr long long LINF=334ll<<53; constexpr int INF=15<<26; constexpr long long MOD=1E9+7;

struct Edge{
    int from,to;
    Edge(int from,int to)
        : from(from),to(to) {};
};
typedef vector<vector<Edge>> Graph;

vector<int > vis(100010);
void dfs(int par, int cur, vector<int> &c,Graph &g){
    if(vis[cur])return ;
    vis[cur]=1;
    int tmp[4]={};
    for(auto e : g[cur]){
        if(c[e.to]!=-1)tmp[c[e.to]]=1;
    }
    for(int i=0; i<4; ++i){
        if(tmp[i]==0){
            c[cur]=i;
            break;
        }
    }
    for(auto e:g[cur]){
        if(e.to!=par)dfs(cur,e.to,c,g);
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> c (n,vector<int>(4));
    for(int i=0; i<n; ++i){
        for(int j=0; j<4; ++j){
            cin >> c[i][j];
        }
    }

    vector<int> X,Y;
    for(int i=0; i<n; ++i){
        X.push_back(c[i][0]);
        X.push_back(c[i][2]);
        Y.push_back(c[i][1]);
        Y.push_back(c[i][3]);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    vector<vector<pair<pair<int,int>,int>>> xx((int)X.size()),yy((int)Y.size());
    Graph g(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<4; ++j){
            if(j%2==0){
                c[i][j]=lower_bound(X.begin(),X.end(),c[i][j])-X.begin();
            }
            if(j%2==1){
                c[i][j]=lower_bound(Y.begin(),Y.end(),c[i][j])-Y.begin();
            }
        }
        xx[c[i][0]].push_back({{c[i][1],c[i][3]},i});
        xx[c[i][2]].push_back({{c[i][1],c[i][3]},i});
        yy[c[i][1]].push_back({{c[i][0],c[i][2]},i});
        yy[c[i][3]].push_back({{c[i][0],c[i][2]},i});
    }
    for(int i=0; i<(int)xx.size(); ++i){
        sort(xx[i].begin(),xx[i].end());
    }
    for(int i=0; i<(int)yy.size(); ++i){
        sort(yy[i].begin(),yy[i].end());
    }
    for(int i=0; i<(int)xx.size(); ++i){
        for(int j=0; j<(int)xx[i].size()-1;){
            int tmp=j+1;
            while(xx[i][j].first.second>xx[i][tmp].first.first){
                //DBG(xx[i][j].first.first,xx[i][j].first.second,xx[i][j].second)
                g[xx[i][j].second].push_back(Edge(xx[i][j].second,xx[i][tmp].second));
                g[xx[i][tmp].second].push_back(Edge(xx[i][tmp].second,xx[i][j].second));
                DBG(xx[i].size(),xx[i][j].second,xx[i][tmp].second,j,tmp)
                ++tmp;
                if(tmp>=xx[i].size())break;
            }
            j=max(j+1,tmp-1);
        }
    }
    for(int i=0; i<(int)yy.size(); ++i){
        for(int j=0; j<(int)yy[i].size()-1;){
            int tmp=j+1;
            while(yy[i][j].first.second>yy[i][tmp].first.first){
                g[yy[i][j].second].push_back(Edge(yy[i][j].second,yy[i][tmp].second));
                g[yy[i][tmp].second].push_back(Edge(yy[i][tmp].second,yy[i][j].second));
                DBG(yy[i][j].second,yy[i][tmp].second,j,tmp)
                ++tmp;
                if(tmp>=yy[i].size())break;
            }
            j=max(j+1,tmp-1);
        }
    }

    vector<int> color(n,-1);



    dfs(-1,0,color,g);
    cout <<"YES" <<"\n";
    for(int i=0; i<n; ++i){
        cout << color[i]+1<<"\n";
    }



    return 0;
}

