#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

//  1
// 2 3
//45 67
//01 23
//propagateではSの演算+がTの演算*に対して分配的、+と*が可換、などの性質を利用をして@演算をつくる
//operation @, where (val1*val2*...)@delay = (val1+delay)*(val2+delay)*...
//examples:
//(val1 add delay)min(val2 add delay)min... = (val1 min val2 min...)add delay
//(val1 add delay)add(val2 add delay)add... = (val1 add val2 add...)add delay add delay ...

struct RangeMax{
    using T = long long;
    T operator()(const T &a, const T &b){return max(a,b);}
    static constexpr T id(){return T(-LINF);};
};

struct RangeAdd{
    using T = long long;
    T operator()(const T &a, const T &b){return a+b;};
    static constexpr T id(){return T(0);};
};

struct Max_Add{
    using V = RangeMax;
    using A = RangeAdd;
    V::T operator()(const V::T &a, const A::T &b, const int &h){return a+b;};
};

struct RangeSum{
    using T = long long;
    T operator()(const T &a, const T &b){return a+b;}
    static constexpr T id(){return T(0);};
};

struct RangeAdd{
    using T = long long;
    T operator()(const T &a, const T &b){return a+b;};
    static constexpr T id(){return T(0);};
};

struct Sum_Add{
    using V = RangeSum;
    using A = RangeAdd;
    V::T operator()(const V::T &a, const A::T &b, const int &h){return a+(b<<h);};
};

template<typename M>
struct LazySegmentTree{
    using Val = typename M::V::T;
    using Del = typename M::A::T;
    typename M::V calc;
    typename M::A composite;
    M act;
    vector<Val> val;
    vector<Del> delay;

    int n,height;
    explicit LazySegmentTree(int size) : n(1),height(0){
        while(n<size){n<<=1;++height;}
        val=vector<Val>(n<<1,calc.id());
        delay=vector<Del>(n<<1,composite.id());
    }
    explicit LazySegmentTree(vector<Val> &v):n(1),height(0){
        while(n < v.size()) {n <<=1;++height;}
        val = vector<Val> (n<<1,calc.id());
        delay=vector<Del>(n<<1,composite.id());
        copy(v.begin(),v.end(),val.begin()+n);
        for(int i=n-1; i>0; --i){val[i]=calc(val[i*2],val[i*2+1]);}
    }
    void propagate(int k,int h){
        val[k]=act(val[k],delay[k],h);
        if(h>0){
            delay[2*k]=composite(delay[2*k], delay[k]);
            delay[2*k+1]=composite(delay[2*k+1], delay[k]);
        }
        delay[k]=composite.id();
    }
    inline void update(int l, int r, Del v){update(l,r,v,1,0,n,height);}
    void update(int l, int r, Del v, int k, int a, int b, int h){
        if(l<=a && b<=r){
            delay[k]=composite(delay[k],v);
            propagate(k,h);
            return;
        }
        propagate(k,h);
        if(b<=l || r<=a){return ;}//
        update(l,r,v,2*k,a,(a+b)/2,h-1);
        update(l,r,v,2*k+1,(a+b)/2,b,h-1);
        val[k]=calc(val[2*k],val[2*k+1]);
    }
    inline Val query(int l,int r){return query(l,r,1,0,n,height);}
    Val query(int l, int r, int k, int a, int b, int h){
        if(b<=l || r<=a){return calc.id();}//
        propagate(k,h);
        if(l<=a && b<=r){
            return val[k];
        }
        Val vall=query(l,r,2*k,a,(a+b)/2,h-1);
        Val valr=query(l,r,2*k+1,(a+b)/2,b,h-1);
        return calc(vall,valr);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LazySegmentTree<Max_Add> lseg(1000);

    return 0;
}
