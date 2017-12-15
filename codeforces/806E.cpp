#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;
struct RangeSum{
    using T = int;
    T operator()(const T &a, const T &b){return a+b;}
    static constexpr T id(){return T(0);};
};

template<typename M>
struct SegmentTree{
    using Val = typename M::T;
    M calc;
    vector<Val> data;
    int n;
    explicit SegmentTree(int size){
        n = 1;
        while(n < size) n <<=1;
       data = vector<Val>(n<<1,calc.id());
    }
    explicit SegmentTree(vector<Val> &v){
        n = 1;
        while(n < v.size()) n <<=1;
        data = vector<Val> (n<<1);
        copy(v.begin(),v.end(),data.begin()+n);
        for(int i=n+(int)v.size(); i<2*n;i++)data[i]=calc.id();
        for(int i=n-1; i>0; --i){data[i]=calc(data[i*2],data[i*2+1]);}
    }
    void update(int i,Val v){
        int k = i + n;
        data[k] = v;
        for(k>>=1; k>=1; k>>=1)data[k] = calc(data[k*2],data[k*2+1]);
    }
    Val query(int l,int r){ //get[a,b)
        Val resl=calc.id(),resr=calc.id();
        for(l += n, r += n; l<r; l>>=1, r>>=1){
            if(l&1)resl=calc(resl, data[l++]);
            if(r&1)resr=calc(data[r-1],resr);
        }
        return calc(resl,resr);
    }
};
struct Problem{
    int n;
    vector<int> a;
    Problem(LL n):n(n),a(n){};

    void solve(){
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        SegmentTree<RangeSum> seg(1e6+10);


    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

