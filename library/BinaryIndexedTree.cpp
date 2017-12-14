#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

//Binary Indexed Tree (Fenwick Tree)
//sum(a,b) = sum of [a,b)
//sum(a) = sum of [0,a)
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    BIT<double> a(100);
    for(int i=0; i<100; ++i){
        a.add(i,i);
    }
    for(int i=0; i<100; ++i){
        cout << a.sum(i+1) << endl;
    }

    return 0;
}
