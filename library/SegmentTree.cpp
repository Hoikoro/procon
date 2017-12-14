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
struct RangeSum{
    using T = long long;
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


struct RangeMinR{
    using T = int;
    void operator()(const T &a, const T &b, T &ret){ret=min(a,b);}
    static constexpr T id(){return T(15<<26);};
};

template<typename M>
struct SegmentTreeR{
    using Val = typename M::T;
    M calc;
    vector<Val> data;
    int n;
    explicit SegmentTreeR(int _n){
        n = 1; while(n < _n) n <<= 1;
        data = vector<Val>(n<<1,calc.id());
    }
    explicit SegmentTreeR(vector<Val> &v){
        n = 1; while(n < v.size()) n <<=1;
        data = vector<Val>(n<<1);
        copy(v.begin(),v.end(),data.begin()+n);
        for(int i=n+(int)v.size(); i<2*n;i++)data[i]=calc.id();
        for(int i=n-1; i>0; --i){calc(data[i*2],data[i*2+1],data[i]);}
    }
    void update(int i,const Val &v){
        int k = i + n;
        data[k] = v;
        for(k>>=1; k>=1; k>>=1)calc(data[2*k],data[2*k+1],data[k]);
    }
    void query(int l,int r, Val &res){//get[a,b)
        Val resl=calc.id(),resr=calc.id();
        for(l += n, r += n; l<r; l>>=1, r>>=1){
            if(l&1)calc(resl, data[l++],resl);
            if(r&1)calc(data[r-1],resr,resr);
        }
        return calc(resl,resr,res);
    }
};





int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    return 0;
}
