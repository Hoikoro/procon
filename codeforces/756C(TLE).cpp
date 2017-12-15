#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#ifdef DEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dreplace(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dreplace(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
template<typename T> using V = vector<T>;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

template<typename T>
struct SegmentTreeR{
    const T INIT_VALUE = tuple<int,int,vector<int>>(0,0,{});
    inline void calc(T &a,const T &b, T &ret){ // sum
        int ld=get<0>(a),lu=get<1>(a),rd=get<0>(b),ru=get<1>(b);
        DBG(get<2>(a).size(),get<2>(b).size())
        get<2>(ret)=get<2>(a);
        for(int i=0; i<rd; ++i){
            if(!get<2>(ret).empty())get<2>(ret).pop_back();
        }
        for(int x: get<2>(b)){
            get<2>(ret).push_back(x);
        }
        //DBG(get<2>(ret).size())
        get<0>(ret)=max(ld,ld-lu+rd);
        if(ld>ld-lu+rd)get<1>(ret)=lu-rd+ru;
        else get<1>(ret)=ru;
        return;
    }
    vector<T> data;
    int n;
    explicit SegmentTreeR(int _n){
        n = 1;
        while(n < _n) n *= 2;
        data = vector<T>(2*n-1,INIT_VALUE);
    }

    void update(int i,T &v){
        int k = i + n-1;
        data[k] = v;
        while(k > 0){
            k = (k-1)/2;
            calc(data[2*k+1],data[2*k+2],data[k]);
        }
    }

    inline void segget(int a,int b, T &ret){ //get[a,b)
        segget(a,b,0,0,n, ret);
    }
private:
    void segget(int a,int b,int k,int l,int r, T &ret){
        DBG(a,b,k)
        if(r <= a or b <= l) {return;}
        if(a <= l and r <= b) {calc(ret,data[k],ret);return;}
        segget(a,b,2*k+1,l,(l+r)/2, ret);
        segget(a,b,2*k+2,(l+r)/2,r, ret);
        return;
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int m;
    cin >> m;
    V<tuple<int,int,int>> op(m);
    for(int i=0; i<m; ++i){
        int p,t,x=0;
        cin >>p >>t;
        if(t)cin >> x;
        op[i]=tie(--p,t,x);
    }
    SegmentTreeR<tuple<int,int,vector<int>>> seg(m);

    for(int i=0; i<m; ++i){
        int perm,opera,x;
        tie(perm,opera,x)=op[i];
        //DBG(i,perm)
        tuple<int,int,vector<int>> tmp;
        if(opera==1){
            get<0>(tmp)=0;
            get<1>(tmp)=1;
            get<2>(tmp)={x};

        }
        else{
            get<0>(tmp)=1;
            get<1>(tmp)=0;
            get<2>(tmp)={};
        }
        seg.update(perm,tmp);
        //auto res=tuple<int,int,vector<int>>(0,0,{});
        DBG(i,perm)
        //seg.segget(0,m,res);
        //DBG(get<2>(res).size())
        if(get<2>(seg.data[0]).empty()) cout << -1 <<"\n";
        else cout << get<2>(seg.data[0]).back() <<"\n";
    }





    return 0;
}

