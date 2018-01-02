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
template<typename T>
struct BIT{
    vector<T> bit;
    int size;
    BIT(int _size) : bit(vector<T>(_size+1,0)),size(_size){}
    void add(int index, T value){
        for(int i=index+1 ; i<=size ; i+=(i&-i)) bit[i]+=value;
    }
    T sum(int a,int b){//sum of[a,b)
        return sum(b)-sum(a);
    }
    T sum(int a){ // sum of[0,a) = sum of bit[0]~bit[a]
        T ret=0;
        for(int i= a ; i>0; i-=(i&-i)) ret+=bit[i];
        return ret;
    }
};
struct Problem{
    int n,q,div,cnt;
    vector<int> perm;
    Problem(LL n,LL q):n(n),q(q),perm(n){};
    int count_smaller(int l, int r, int s, vector<BIT<short>> &bit){
        DBG(div,l,r)
        int ret=0;
        while(l%div!=0 && l<r){
            if(perm[l]<s)++ret;
            ++l;
        }
        DBG(l,r)
        while(l+div<r){
            ret+=bit[l/div].sum(s);
            l+=div;
        }
        DBG(l,r)
        while(l<r){
            if(perm[l]<s)++ret;
            ++l;
        }
        DBG(l,r,s,ret)
        return ret;
    }

    void solve(){
        iota(perm.begin(),perm.end(),0);
        LL ans=0;
        div=ceil(sqrt(n)),cnt=(n+div-1)/div;
        vector<BIT<short>> smaller(cnt,BIT<short>(n));
        for(int i=0; i<n; ++i){
            smaller[i/div].add(i,(short)1);
        }
        for(int i=0; i<q; ++i){
            int l,r;
            cin >> l >> r;
            --l;--r;
            if(l==r){
                cout << ans <<"\n";
                continue;
            }
            if(l>r)swap(l,r);
            LL difl=count_smaller(l+1,r,perm[l],smaller);
            difl=(r-l-1)-difl*2;
            LL difr=count_smaller(l+1,r,perm[r],smaller);
            difr=difr*2-(r-l-1);
            //modify BIT
            smaller[l/div].add(perm[l],(short)-1);
            smaller[l/div].add(perm[r],(short)1);
            smaller[r/div].add(perm[l],(short)1);
            smaller[r/div].add(perm[r],(short)-1);
            if(perm[l]<perm[r])++ans;
            else --ans;
            swap(perm[l],perm[r]);
            DBG(perm)
            ans=ans+difl+difr;
            DBG(difl,difr,ans)
            cout << ans <<"\n";
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,q;
    cin >> n >>q ;
    Problem p(n,q);
    p.solve();
    return 0;
}

