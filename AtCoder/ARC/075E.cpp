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
    LL n,k;
    vector<LL> a,sum,pos;
    vector<pair<LL,LL>> s;
    BIT<LL> bit;
    Problem(LL n):n(n),a(n+1),sum(n+1),pos(n+1),bit(n){};

    void solve(){
        cin >> k;
        for(int i=1; i<=n; ++i){
            cin >> a[i];
            a[i]-=k;
        }
        for(int i=1; i<=n; ++i){
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1; i<=n; ++i){
            s.emplace_back(sum[n]-sum[i-1],i);
        }
        sort(s.begin(),s.end());
        for(int i=0; i<n; ++i){
            pos[s[i].second]=i;
        }
        LL ans =0;
        for(int i=1; i<=n; ++i){
            LL tmp=sum[n]-sum[i];
            int it= lower_bound(s.begin(),s.end(),make_pair(tmp,0ll))-s.begin();
            bit.add(pos[i],1);
            ans+=bit.sum(it,n);
            /*LL lb=-1,ub=i;
            while(ub-lb>1){
                LL mid = (lb+ub)/2;
                if(check(i,mid)) ub=mid;
                else lb=mid;
            }
            ans+=ub;*/
            DBG(i,ans)
        }
        cout << ans << "\n";
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

