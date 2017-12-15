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

struct Problem{
    string s,t;
    int q;
    void solve(){
        cin >> s >> t >> q;
        vector<int> sa(s.length()+1),sb(s.length()+1),ta(t.length()+1),tb(t.length()+1);
        for(int i=0; i<s.length(); ++i){
            if(s[i]=='A')sa[i+1]=1;
            else sb[i+1]=1;
        }
        for(int i=0; i<t.length(); ++i){
            if(t[i]=='A')ta[i+1]=1;
            else tb[i+1]=1;
        }
        for(int i=0; i<s.length(); ++i){
            sa[i+1]+=sa[i];
            sb[i+1]+=sb[i];
        }
        for(int i=0; i<t.length(); ++i){
            ta[i+1]+=ta[i];
            tb[i+1]+=tb[i];
        }
        for(int i=0; i<q; ++i){
            int sl,sr,tl,tr;
            cin >> sl >> sr >> tl >> tr;
            --sl;--tl;
            int ds= (sa[sr]-sa[sl])*2+(sb[sr]-sb[sl]);
            int dt= (ta[tr]-ta[tl])*2+(tb[tr]-tb[tl]);
            cout << (abs(ds-dt)%3==0?"YES":"NO")<<"\n";
        }

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Problem p;
    p.solve();
    return 0;
}

