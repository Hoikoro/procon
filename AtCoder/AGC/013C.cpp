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
    LL n,l,t,init,rr;
    vector<LL> pos,dir,right,left;
    vector<pair<LL,LL>> fin;
    Problem(LL n):n(n),rr(-1),pos(n),dir(n),fin(n){};

    void solve(){
        cin >> l >> t;
        bool rev=true, cl=true;
        for(LL i=0; i<n; ++i){
            cin >> pos[i] >> dir[i];
            if(dir[i]==1){
                rev=false;
                if(rr==-1)rr=i;
                fin[i]={(pos[i]+t)%l,1};
            }else{
                cl=false;
                fin[i]={((pos[i]-t)%l+l)%l,2};
            }
        }
        if(rev){
            for(LL i=0; i<n; ++i){
                cout << ((pos[i]-t)%l+l)%l <<"\n";;
            }
            return;
        }
        if(cl){
            for(LL i=0; i<n; ++i){
                cout << ((pos[i]+t)%l+l)%l <<"\n";;
            }
            return;
        }
        for(LL i=0; i<n; ++i){
            if(dir[i]==1){
                right.push_back((pos[rr]-pos[i]+l)%l);
            }else{
                left.push_back((pos[i]-pos[rr]+l)%l);
           }
        }
        sort(right.begin(),right.end());
        sort(left.begin(),left.end());
        init=left[0];
        DBG(init)
        for(auto & x: left){
            x-=init;
        }
        DBG(left)
        sort(fin.begin(),fin.end());
        LL ub=1e9, lb=-1;
        LL tmp=0;
        while(ub-lb>1){
            LL mid=(ub+lb)/2;
            if(check(mid,tmp))ub=mid;
            else lb=mid;
        }
        LL findir=ub%2==0?1:2;
        LL finpos=0;
        check(ub,finpos);
        DBG(finpos,findir)
        finpos=((finpos+pos[rr])%l+l)%l;
        LL it=lower_bound(fin.begin(),fin.end(),make_pair((LL)finpos,findir))-fin.begin();
        DBG(ub,it)
        for(LL i=0; i<n; ++i){
            DBG( fin[((i+it-rr)%n+n)%n])
            cout << fin[((i+it-rr)%n+n)%n].first <<"\n";
        }
    }
    bool check(LL m, LL &tm){
        LL sum=init,rcnt=(m+1)/2,lcnt=m/2;tm=init;
        DBG(tm)
        sum+=rcnt/(LL)right.size()*l+(rcnt%(LL)right.size()==0?0:right[rcnt%(LL)right.size()]);
        tm-=rcnt/(LL)right.size()*l+(rcnt%(LL)right.size()==0?0:right[rcnt%(LL)right.size()]);
        DBG(m,sum,tm)
        sum+=lcnt/(LL)left.size()*l+(lcnt%(LL)left.size()==0?0:left[lcnt%(LL)left.size()]);
        tm+=lcnt/(LL)left.size()*l+(lcnt%(LL)left.size()==0?0:left[lcnt%(LL)left.size()]);
        DBG(m,sum,tm)
        if(m%2==0){
            assert((tm-sum+t*2)%2==0);
            tm=(tm-sum+t*2)/2;
        }else{
            //tm=round((double)tm/2+(double)t-(double)sum/2.0);
            assert((tm+sum-t*2)%2==0);
            tm=(tm+sum-t*2)/2;

        }
        DBG(tm)
        return sum>=2*t;
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

