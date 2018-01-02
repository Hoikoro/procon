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
    int n,l;
    BIT<int> bit;
    Problem(LL n):n(n),bit(n){};

    void solve(){
        l=n;
        cout << 1 <<" ";
        for(int i=0; i<n; ++i){
            int p;
            cin >> p;
            --p;
            bit.add(p,1);
            if(p==l-1){
                while(bit.sum(l-1,l)==1)--l;
            }
            DBG(l)
            cout << bit.sum(0,l)+1 <<((i!=n-1)?" ":"\n");
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

