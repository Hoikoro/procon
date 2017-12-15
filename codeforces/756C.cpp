#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first
#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dreplace(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...) ;
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
    //<lowest, add, where[top], from_left,from_right,segment_length>
    const T INIT_VALUE = vector<int>({0,0,-1,0,0,1});
    inline void calc(const T &a,const T &b, T &ret){ // sum
        ret[5]=a[5]+b[5];
        int ld=a[0],lu=a[1],rd=b[0],ru=b[1];
        //else get<2>(ret)=get<2>(a);
        ret[0]=max(ld,ld-lu+rd);
        if(ld>ld-lu+rd){
            ret[1]=lu-rd+ru;
            ret[4]=b[1];
            ret[3]=ret[1]-ret[4];
        }
        else{
            ret[1]=ru;
            ret[4]=b[1];
            ret[3]=0;
        }
        DBG(lu-rd)
        if(b[2]>=0){
            ret[2]=b[2]+a[5];
        }else if(lu-rd<=0){
            ret[2]=-1;
        }else{
            int k=(&ret-&data[0]);
            ret[2]=binary_search(k,lu-rd);
        }
        return;
    }
    int binary_search(int k, int cnt){
        DBG(k)
        int sum=0,res=0;
        while(data[k][5]>1){
            if(sum+data[k][3]>=cnt)k=2*k+1;
            else{
                sum+=data[k][3];
                res+=data[2*k+1][5];
                k=2*k+2;
            }
        }
        DBG("result",k,res)
        return res;
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
    SegmentTreeR<vector<int>> seg(m);
    for(int i=0; i<m; ++i){
        vector<int> init={0,0,-1,0,0,1};
        seg.update(i,init);
    }
    vector<int> val(m);
    for(int i=0; i<m; ++i){
        int perm,opera,x;
        tie(perm,opera,x)=op[i];
        DBG(i,perm)
        vector<int> tmp(6);
        if(opera==1){
            tmp={0,1,0,0,0,1};
            val[perm]=x;
        }
        else{
            tmp={1,0,-1,0,0,1};
        }
        seg.update(perm,tmp);
        DBG(i,perm)
        //seg.segget(0,m,res);
        DBG(seg.data[0][2])
        if (seg.data[0][2]==-1) cout << -1 <<"\n";
        else cout << val[seg.data[0][2]] <<"\n";
    }





    return 0;
}

