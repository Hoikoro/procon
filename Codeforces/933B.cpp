#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision


#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif

using LL = long long ;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

namespace Problem{
using namespace std;
/*to paste snipets///*/
class Writer{
static ostringstream oss;
public:template<class T> void appendln(const vector<vector<T>> &ans,string spl=" ", string el="\n"){for(int i=0; i<(int)ans.size(); ++i){for(int j=0; j<(int)ans[i].size(); ++j){oss << ans[i][j];oss << (j==(int)ans[i].size()-1?el:spl);}}}
    template<class T> void appendln(const vector<T>& ans, string spl=" "){for(int i=0; i<(int)ans.size(); ++i){oss << ans[i] << (i==(int)ans.size()-1?"\n":spl);}}
    template<class T> void appendln(const T& answer){oss << answer << "\n";}
    template<class T> void append(const T& answer){oss << answer;}
    void appends(const string spl){oss.seekp((int)oss.tellp()-1);oss<<"\n";}
    template<class F, class... R>void appends(const string spl,const F& fi, const R&... rest){oss << fi << spl; appends(spl, rest...);}
    static void write(){cout << oss.str();}
    Writer(){static bool is_single =true;assert(is_single);is_single=false;};
};ostringstream Writer::oss;

class Solver{
public:
    LL p,k;

    void solve(){
        cin >> p>> k;
        vector<LL> coeff(1);
        LL maxi = k-1;
        LL kk = k*2;
        while(maxi<p){

            if((p-maxi+kk-1)/kk<=k-1){
                break;
            }
            for(int i=0; i<2; ++i){
                coeff.push_back(0);
            }
            maxi += kk*(k-1);
            kk*=k*2;
        }
        vector<LL> powk((int)coeff.size());
        vector<LL> pos((int)coeff.size());
        vector<LL> neg((int)coeff.size());
        powk[0]=1;
        DBG(powk)
        for(int i=1; i<(int)powk.size(); ++i){
            powk[i]=powk[i-1]*k;
        }
        DBG(powk)
        pos[0]=k-1;
        neg[0]=0;
        for(int i=1; i<(int)coeff.size(); ++i){
            if(i%2 ==0 ){
                pos[i] = pos[i-1]+powk[i]*(k-1);
                neg[i] = neg[i-1];
            }else{
                pos[i] = pos[i-1];
                neg[i] = neg[i-1] + powk[i]*(k-1);
            }
        }
        for(int i=(int)coeff.size()-1; i>=0; --i){
            //cerr << i << " "<<p <<" "<<p+neg[i] <<" "<<powk[i] <<"\n";
            if(i%2==0){
                coeff[i] = (p+neg[i])/powk[i];
                p-=coeff[i]*powk[i];
            }else{
                coeff[i] = (-p+pos[i])/powk[i];
                p+=coeff[i]*powk[i];
            }
        }
        for(int i=0; i<(int)coeff.size(); ++i){
            //cerr << coeff[i] << (i==(int)coeff.size()-1?"\n":" ");
        }
        for(int i=0; i<(int)coeff.size(); ++i){
            if(coeff[i]>=k){
                cout << -1 <<"\n";
                return;
            }
        }
        cout << (int)coeff.size() <<"\n";
        for(int i=0; i<(int)coeff.size(); ++i){
            cout << coeff[i] << (i==(int)coeff.size()-1?"\n":" ");
        }
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    Problem::Solver sol;
    sol.solve();
    Problem::Writer::write();
    return 0;
}

