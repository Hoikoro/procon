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

class FastFourierTransform{
    int len;
    vector<complex<double>> a,b;
    vector<double> conv;
    vector<complex<double>> p_roots,inv_roots;
    vector<complex<double>> fft(const vector<complex<double>> &a, bool inv=false,int intv =1){
        if(intv == len){
            assert(a.size()==1);
            return a;
        }
        vector<vector<complex<double>>> partial(2);
        for(int i=0; i<(int)a.size(); ++i){
            partial[i%2].push_back(a[i]);
        }
        auto even = fft(partial[0],inv,intv*2);
        auto odd = fft(partial[1],inv,intv*2);
        vector<complex<double>> ret((int)a.size());
        if(inv){
            for(int i=0,j=0; i<(int)ret.size(); ++i){
                ret[i]=even[j]+inv_roots[i*intv]*odd[j];
                ++j;if(j>=(int)even.size())j-=(int)even.size();
            }
        }else{
            for(int i=0,j=0; i<(int)ret.size(); ++i){
                ret[i]=even[j]+p_roots[i*intv]*odd[j];
                ++j;if(j>=(int)even.size())j-=(int)even.size();
            }
        }
        return ret;
    }
    vector<complex<double>> mul(const vector<complex<double>> &a, const vector<complex<double>> &b){
        auto ret = a;
        for(int i=0; i<len; ++i){
            ret[i]*=b[i];
        }
        return ret;
    }
    vector<double> get_real(const vector<complex<double>>&a){
        vector<double> ret((int)a.size());
        for(int i=0; i<(int)a.size(); ++i){
            ret[i]=a[i].real()/(double)len;
        }
        return ret;
    }
public:
    FastFourierTransform(vector<double> &a_, vector<double> &b_){
        int msz =(int)a_.size()+(int)b_.size();
        len =1;
        while(len<msz)len<<=1;
        a.resize(len);
        b.resize(len);
        for(int i=0; i<a_.size(); ++i){a[i]={a_[i],0};}
        for(int i=0; i<b_.size(); ++i){b[i]={b_[i],0};}
        p_roots.resize(len+1,{1,0});
        inv_roots.resize(len+1,{1,0});
        for(int i=1; i<len; ++i){
            p_roots[i]={cos(acos(-1.0)*2.0*i/len),sin(acos(-1.0)*2.0*i/len)};
            inv_roots[i]={cos(acos(-1.0)*2.0*i/len),-sin(acos(-1.0)*2.0*i/len)};
        }
    };
    vector<double> convolute(){
        return conv = get_real(fft(mul(fft(a),fft(b)),true));
    }
};

struct Problem{
    int n;
    vector<double> a,b;
    Problem(LL n):n(n),a(n+1),b(n+1){};

    void solve(){
        for(int i=1; i<=n; ++i){
            cin >> a[i] >> b[i];
        }
        auto ans = FastFourierTransform(a,b).convolute();
        for(int i=1;i<=2*n ;++i){
            cout << (int)round(ans[i])<<"\n";
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

