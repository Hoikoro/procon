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
void ok(){cout << "YES" <<"\n"; exit(0);}
void fail(){cout << "NO" <<"\n"; exit(0);}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    LL n;
    cin >> n;
    if(n==1) ok();
    vector<LL> a(n),b(n),c(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    LL sum=accumulate(a.begin(),a.end(),0ll);
    if(sum%(n*(n+1)/2)!=0)fail();
    LL cnt=sum/(n*(n+1)/2);
    a.push_back(a[0]);
    LL removes=0;
    for(int i=0; i<n; ++i){
        LL dif=a[i+1]-a[i];
        if((cnt-dif)%n!=0)fail();
        else{
            b[i]=(cnt-dif)/n;
            if(b[i]<0)fail();
            removes+=b[i];
        }
    }
    if(removes!=cnt)fail();
    /*a.pop_back();
    vector<int> visited(n);
    int adddif=0,add=0;
    for(int i=0; i<2*n; ++i){
        int now=i%n;
        if(visited[now]==0){
            adddif+=b[now];
            visited[now]=1;
        }
        else {
            adddif-=b[now];
            add-=b[now]*n;
        }
        add+=adddif;
        c[(now+1)%n]+=add;
    }
    for(int i=0; i<n; ++i){
        if(c[i]!=a[i])fail();
    }*/

    ok();



    return 0;
}

