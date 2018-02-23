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

template<long long Mod=MOD>
struct Modint{
    public:
    //long long Mod = MOD;
    long long v;
    template<typename T> Modint(T x){
        x %= Mod;
        long long y = (long long)x;
        if(y<0) y+=Mod;
        v=y;
    }
    Modint():v(0){}
    Modint &operator+=(Modint a){
        v=(v+a.v);
        if(v>=Mod) v-=Mod;
        return *this;
    }
    Modint &operator-=(Modint a){
        v=(v-a.v);
        if(v<0)v+=Mod;
        return *this;
    }
    Modint &operator*=(Modint a){
        v=(v*a.v)%Mod;
        return *this;
    }
    Modint &operator/=(Modint a){
        v=(v*a.mpow(Mod-2).v)%Mod;
        return *this;
    }
    Modint mpow(Modint n){return mpow(n.v);}
    Modint mpow(long long n){
        long long i=1,p=v;
        Modint ret(1);
        while(i<=n){
            if(i&n) ret*=p;
            i=(i<<1);
            p=(p*p)%Mod;
        }
        return ret;
    }
    Modint operator+(Modint a){
        long long t= (v)+(a.v);
        return Modint(t);
    }
    Modint operator-(Modint a){
        long long t= (v)-(a.v);
        return Modint(t);
    }
    Modint operator*(Modint a){
        long long t= (v)*(a.v);
        return Modint(t);
    }
    Modint operator/(Modint a){
        return a.mpow(Mod-2)**this;
    }
};
template<long long M>
ostream& operator<< (ostream& os, const Modint<M> m) {
    return os << m.v;
}

template<LL mod, LL primitive_root>
class NumberTheoreticTransform{
    LL len;
    vector<Modint<mod>> a,b,conv;
    Modint<mod> z,inv_z; //z^len = 1 ("mod" mod)
    vector<Modint<mod>> ntt(const vector<Modint<mod>> &a,Modint<mod> base){
        if(base.v==1){
            assert(a.size()==1);
            return a;
        }
        vector<vector<Modint<mod>>> partial(2,vector<Modint<mod>>((int)a.size()/2));
        for(int i=0; i<(int)a.size(); ++i){
            partial[i%2][i/2]=a[i];
        }
        auto even = ntt(partial[0],base*base);
        auto odd = ntt(partial[1],base*base);
        vector<Modint<mod>> ret((int)a.size());

        auto base2=Modint<mod>(1);
        for(int i=0,j=0; i<(int)ret.size(); ++i,base2*=base){
            DBG(base2)
            ret[i]=even[j]+base2*odd[j];
            ++j;if(j>=(int)even.size())j-=(int)even.size();
        }
        return ret;
    }
    vector<Modint<mod>> mul(const vector<Modint<mod>> &a, const vector<Modint<mod>> &b){
        auto ret = a;
        for(int i=0; i<len; ++i){
            ret[i]*=b[i];
        }
        return ret;
    }
    vector<Modint<mod>> regularize(const vector<Modint<mod>>&a){
        vector<Modint<mod>> ret((int)a.size());
        for(int i=0; i<(int)a.size(); ++i){
            ret[i]=Modint<mod>(len).mpow(mod-2)*a[i];
        }
        return ret;
    }
public:
    NumberTheoreticTransform(vector<LL> &a_, vector<LL> &b_){
        int msz =(int)a_.size()+(int)b_.size();
        len =1;
        while(len<msz)len<<=1;
        a.resize(len);
        b.resize(len);
        z=(Modint<mod>(primitive_root)).mpow((mod-1)/len);//周期注意
        inv_z=z.mpow(len-1);
        for(int i=0; i<a_.size(); ++i){a[i]=a_[i];}
        for(int i=0; i<b_.size(); ++i){b[i]=b_[i];}
    };
    vector<Modint<mod>> convolute(){
        return conv = regularize(ntt(mul(ntt(a,z),ntt(b,z)),inv_z));
    }
};

struct Problem{
    int n;
    vector<LL> a,b;
    Problem(LL n):n(n),a(n+1),b(n+1){};

    void solve(){
        for(int i=1; i<=n; ++i){
            cin >> a[i] >> b[i];
        }
        auto ans = NumberTheoreticTransform<1004535809,3>(a,b).convolute();
        DBG(ans)
        for(int i=1;i<=2*n ;++i){
            cout << ans[i]<<"\n";
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

