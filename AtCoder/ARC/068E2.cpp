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

struct RangeAdd{
    using T = long long;
    T operator()(const T &a, const T &b){return a+b;};
    static constexpr T id(){return T(0);};
};

struct RangeSum{
    using T = long long;
    T operator()(const T &a, const T &b){return a+b;}
    static constexpr T id(){return T(0);};
};

struct Add_Sum{
    using V = RangeAdd;
    using A = RangeSum;
    V::T operator()(const V::T &a, const A::T &b, const int &h){return a+(b<<h);};
};

template<typename M>
struct LazySegmentTree{
    using Val = typename M::V::T;
    using Del = typename M::A::T;
    typename M::A composite;
    typename M::V calc;
    M act;
    vector<Val> val;
    vector<Del> delay;
    //vector<char> has_delay;

    int n,height;
    explicit LazySegmentTree(int size) : n(1),height(0){
        while(n<size){n<<=1;++height;}
        val=vector<Val>(n<<1,calc.id());
        delay=vector<Del>(n<<1,composite.id());
        //has_delay=vector<char>(n<<1,0);
    }
    void propagate(int k,int h){
        val[k]=act(val[k],delay[k],h);
        delay[2*k]=composite(delay[2*k], delay[k]);
        delay[2*k+1]=composite(delay[2*k+1], delay[k]);
        delay[k]=composite.id();
    }
    void act_leaf(int k){
        val[k]=act(val[k],delay[k],0);
        delay[k]=composite.id();
    }
    void update(int l, int r, Del v){
        l+=n;r+=n;
        int hl=__builtin_ctz(l),hr=__builtin_ctz(r);
        for(int h=height; h>hl; --h){propagate(l>>h,h);}
        for(int h=height,rr=r-1; h>hr; --h){propagate(rr>>h,h);}
        for(int h=0;l<r; l>>=1, r>>=1,++h){
            if(l&1){
                delay[l]=composite(delay[l],v);
                //has_delay[l]=1;
                if(l<n)propagate(l,h);
                else act_leaf(l);
            }
            val[l>>1]=calc(val[(l>>1)<<1],val[((l>>1)<<1)|1]);
            ++l;
            if(r&1){
                delay[r-1]=composite(delay[r-1],v);
                //has_delay[r-1]=1;
                if(r-1<n)propagate(r-1,h);
                else act_leaf(r-1);
            }
            val[(r-1)>>1]=calc(val[((r-1)>>1)<<1],val[(((r-1)>>1)<<1)|1]);
        }
         for(--l;l>1;l>>=1){val[l>>1]=calc(val[(l>>1)<<1],val[((l>>1)<<1)|1]);}
    }
    Val query(int l, int r){
        Val resl=calc.id(),resr=calc.id();
        l+=n;r+=n;
        int hl=__builtin_ctz(l),hr=__builtin_ctz(r);
        for(int h=height; h>hl; --h){propagate(l>>h,h);}
        for(int h=height,rr=r-1; h>hr; --h){propagate(rr>>h,h);}
        if(l&1){
            act_leaf(l);
            resl=calc(resl,val[l++]);
        }
        if(r&1){
            act_leaf(r-1);
            resr=calc(val[r-1],resr);
        }
        l>>=1;r>>=1;
        for(int h=1;l<r; l>>=1, r>>=1,++h){
            if(l&1){
                propagate(l,h);
                resl=calc(resl,val[l++]);
            }
            if(r&1){
                propagate(r-1,h);
                resr=calc(val[r-1],resr);
            }
        }
        return calc(resl,resr);
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
    LazySegmentTree<Add_Sum> seg(m+1);
    for(int i=1; i<=m; ++i){
        DBG(i)
        int ans=0;
        while(get<0>(*it)<i && it<s.end()){
            seg.update(get<1>(*it),get<2>(*it)+1,1);
            it++;
        }
        ans=s.end()-it;
        for(int j=i; j<=m; j+=i){
            ans+=seg.query(j,j+1);
        }
        cout << ans <<"\n";
    }
    return 0;
}

