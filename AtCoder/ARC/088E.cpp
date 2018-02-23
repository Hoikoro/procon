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
    string s;
    void solve(){
        vector<deque<LL>> a(26);
        cin >> s;
        LL l = s.length();
        for(int i=0; i<l; ++i){
            a[s[i]-'a'].push_back(i);
        }
        vector<pair<LL,LL>> pairs;
        LL single=-1;
        for(int i=0; i<26; ++i){
            if((int)a[i].size()%2==1){
                if(single>-1){
                    cout << -1<<"\n";
                    return;
                }
                single = a[i][(int)a[i].size()/2];
            }
            while((int)a[i].size()>1){
                int l = a[i][0],u=a[i].back();
                pairs.emplace_back(u-l,l);
                a[i].pop_back();
                a[i].pop_front();
            }
        }
        vector<LL> perm(l);
        sort(pairs.rbegin(),pairs.rend());
        for(int i = 0;i<(int)pairs.size();++i){
            perm[pairs[i].second]=i;
            perm[pairs[i].second+pairs[i].first]=l-1-i;
        }
        if(single>-1){
            perm[single]=l/2;
        }
        BIT<LL> bit(l);
        LL ans =0;
        for(int i=0; i<l; ++i){
            DBG(i,l,perm[i])
            ans+=abs(i-perm[i]-bit.sum(perm[i],l));
            bit.add(perm[i],1);
        }
        cout << ans <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    Problem p;
    p.solve();
    return 0;
}

