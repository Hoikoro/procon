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
    T rsum(int a){
        return sum(a,size);
    }
};
struct Problem{
    int n;
    vector<LL> t,p;
    BIT<LL> tt,pp;
    Problem(LL n):n(n),t(42),p(42),tt(42),pp(42){};

    void solve(){
        for(int i=0; i<n; ++i){
            LL tmp,pow2=1;
            cin >> tmp;
            for(int j=0; j<42; ++j,pow2<<=1){
                if(tmp==pow2){
                    t[j]++;
                    //tt.add(j,1);
                    break;
                }else if(tmp<pow2){
                    p[j-1]++;
                    pp.add(j-1,1);
                    break;
                }
            }
        }
        endseq();
        vector<int> ans;
        while(1){
            if(!check())break;
            else{
                ans.push_back(t[0]);
                t[0]--;
                pp.add(0,1);
                endseq();
            }
        }
        sort(ans.begin(),ans.end());
        if((int)ans.size()==0)cout << -1 <<endl;
        else{
            for(int i=0; i<(int)ans.size(); ++i){
                cout << ans[i];
                if(i<(int)ans.size())cout <<' ';
            }
            cout <<"\n";
        }
    }
    bool check(){
        for(int i=0; i<42; ++i){
            if(t[i]<pp.rsum(i))return false;
        }
        return true;
    }
    void endseq(){
        for(int i=1; i<42; ++i){
            int tmp=t[i]-t[i-1];
            if(tmp>0){
                t[i]-=tmp;
                pp.add(i-1,tmp);
            }
        }
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

