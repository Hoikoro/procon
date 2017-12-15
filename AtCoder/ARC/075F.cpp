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
    LL d,ans;
    vector<LL> nines;
    Problem(LL d):d(d),nines(18){};
    long long pow_(long long a, long long n){
        long long i=1,ret=1,p=a;
        while(i<=n){
            if(i&n) ret*=p;
            i=(i<<1);
            p*=p;
        }
        return ret;
    }
    bool check(vector<LL> &c){
        for(auto x:c){
            if(abs(x)>=10)return false;
        }
        return true;
    }
    void solve(){
        if(d%9!=0){cout << 0 <<"\n";return;}
        for(int i=1; i<(int)nines.size(); ++i){
            nines[i]=nines[i-1]*10+9;
        }
        for(int lz=0; lz<=9; ++lz){ //odd
            int loop=min(8,lz);
            for(int j=0; j<(1<<loop); ++j){
                vector<LL> cf(loop+1);//1,3,5,7,9,11
                LL tmp=d,cnt=1;
                for(int i =loop;i>=0; --i){
                    LL den = nines[i*2+1]*pow_(10,lz-i);
                    if((i>0 )&& ((j>>(i-1))&1)){
                        cf[i]=ceil(((double)tmp+0.1)/(double)den);
                    }else{
                        cf[i]=floor(((double)tmp+0.1)/(double)den);
                    }
                    tmp-=cf[i]*den;
                }
                //DBG(lz,j,cf,tmp)
                if(tmp!=0 or !check(cf))continue;
                for(int i=0; i<cf.size(); ++i){
                    cnt*=(10-abs(cf[i]));
                }
                DBG(cf)
                DBG(lz,j,cnt)
                if(lz<(int)cf.size())cnt=cnt/(10-abs(cf.back()))*(9-abs(cf.back()));
                else{
                    cnt*=pow_(10,lz-(int)cf.size()+1)-1;
                }
                DBG(lz,j,cnt)
                ans+=cnt;
            }
        }
        for(int lz=0; lz<=9; ++lz){ //even
            int loop=min(8,lz);
            for(int j=0; j<(1<<(loop-1)); ++j){
                vector<LL> cf(loop+1);//0,2,4,6,8,10
                LL tmp=d,cnt=10;//center
                for(int i =loop;i>=1; --i){
                    LL den = nines[i*2]*pow_(10,lz-i);
                    if((i>1) && ((j>>(i-2))&1)){
                        cf[i]=ceil(((double)tmp+0.1)/(double)den);
                    }else{
                        cf[i]=floor(((double)tmp+0.1)/(double)den);
                    }
                    tmp-=cf[i]*den;
                }
                //DBG(lz,j,cf,tmp,2)
                if(tmp!=0 or !check(cf))continue;
                for(int i=1; i<cf.size(); ++i){
                    cnt*=(10-abs(cf[i]));
                }
                DBG(cf,2)
                DBG(lz,j,cnt)
                if(lz<(int)cf.size())cnt=cnt/(10-abs(cf.back()))*(9-abs(cf.back()));
                else{
                    cnt*=pow_(10,lz-(int)cf.size()+1)-1;
                }
                DBG(lz,j,cnt)
                ans+=cnt;
            }
        }
        cout <<ans <<"\n";
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

