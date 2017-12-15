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
template<typename T, typename S>
struct LazySegmentTree{
    static constexpr T id_val=0;
    static constexpr S id_delay=0;
    inline void composite_delay(S &a, S &b){
        a+=b;
    }
    inline void propagate(int k,int a,int b){
        data[k].val+=data[k].delay*(b-a);
        if(k<n){
            composite_delay(data[2*k].delay, data[k].delay);
            composite_delay(data[2*k+1].delay, data[k].delay);
        }
        data[k].delay=id_delay;
    }
    inline T calc(T a,T b){
        return a+b;
    }

    struct Node{
        T val; S delay;
        Node(){val=id_val;delay=id_delay;}
    };
    int n;
    vector<Node> data;
    explicit LazySegmentTree(int size){
        n=1;
        while(n<size)n*=2;
        data=vector<Node>(2*n,Node());
    }
    inline void update(int l,int r,S v){update(l,r,v,1,0,n);}
    void update(int l, int r, S v, int k, int a, int b){
        if(l<=a && b<=r){
            composite_delay(data[k].delay,v);
            propagate(k,a,b);
            return ;
        }
        propagate(k,a,b);
        if(b<=l || r<=a){return ;}//
        update(l,r,v,2*k,a,(a+b)/2);
        update(l,r,v,2*k+1,(a+b)/2,b);
        data[k].val=calc(data[2*k].val,data[2*k+1].val);
    }
    inline T get(int l,int r){return get(l,r,1,0,n);}
    T get(int l, int r, int k, int a, int b){
        if(b<=l || r<=a){return id_val;}//
        propagate(k,a,b);
        if(l<=a && b<=r){
            return data[k].val;
        }
        T vall=get(l,r,2*k,a,(a+b)/2);
        T valr=get(l,r,2*k+1,(a+b)/2,b);
        return calc(vall,valr);
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<tuple<int,int,int>> s(n);
    for(int i=0; i<n; ++i){
        int l,r;
        cin >> l >> r;
        s[i]=make_tuple(r-l+1,l,r);
    }
    sort(s.begin(),s.end());

    auto it=s.begin();
    LazySegmentTree<LL,LL> seg(m+1);
    for(int i=1; i<=m; ++i){
        int ans=0;
        while(get<0>(*it)<i && it<s.end()){
            seg.update(get<1>(*it),get<2>(*it)+1,1);
            it++;
        }
        ans=s.end()-it;
        for(int j=i; j<=m; j+=i){
            ans+=seg.get(j,j+1);
        }
        cout << ans <<"\n";
    }

    return 0;
}
