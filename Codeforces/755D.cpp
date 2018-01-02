#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#define DBG(...) {string dst__=#__VA_ARGS__;dreplace(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dreplace(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

template<typename T>
struct SegmentTree{
    const T INIT_VALUE = 0;
    inline T calc(T a,T b){ // sum
        return a+b;
    }
    vector<T> data;
    int n;
    explicit SegmentTree(int _n){
        n = 1;
        while(n < _n) n *= 2;
        data = vector<T>(2*n-1,INIT_VALUE);
    }
    void update(int i,T v){
        int k = i + n-1;
        data[k] = data[k]+v;
        while(k > 0){
            k = parent(k);
            data[k] = calc(data[get_left(k)],data[get_right(k)]);
        }
    }
    inline T get(int a,int b){ //get[a,b)
        return get(a,b,0,0,n);
    }
private:
    T get(int a,int b,int k,int l,int r){
        if(r <= a or b <= l) return 0;
        if(a <= l and r <= b) return data[k];
        T vl = get(a,b,get_left(k),l,(l+r)/2);
        T vr = get(a,b,get_right(k),(l+r)/2,r);
        return calc(vl,vr);
    }
    inline int get_left(int x){return 2*x+1;}
    inline int get_right(int x){return 2*x+2;}
    inline int parent(int x){return (x-1)/2;}
};

int main(){
    //cin.tie(0);
    //ios_base::sync_with_stdio(false);
    int n,k;
    scanf("%d%d",&n,&k);
    SegmentTree<LL> seg(n);
    if(k*2>n)k=n-k;
    int now=0,nxt=k;
    LL ans=1;
    for(int i=0; i<n; ++i){
        if(now<nxt){
            LL tmp=seg.get(now+1,nxt);
            ans+=tmp+1;
            seg.update(now,1);
            seg.update(nxt,1);
        }else{
            LL tmp=seg.get(now+1,n)+seg.get(0,nxt);
            ans+=tmp+1;
            seg.update(now,1);
            seg.update(nxt,1);
        }
        printf("%lld", ans);
        if(i<n-1)printf(" ");
        else printf("\n");
        now=nxt;
        nxt=(now+k)%n;
    }



    return 0;
}

