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
    LL h,w,a,b;
    void no(){cout <<"No"<<"\n"; exit(0);}

    void solve(){
        cin >> h >> w >> a >> b;
        if(h%a==0 and w%b==0)no();
        vector<vector<LL>> ans (h,vector<LL>(w));
        LL sum=0,cnt=0;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                if(i%a==0 and j%b==0)ans[i][j]=1,sum++;
                if(i%a==h%a and j%b==w%b)cnt++;
            }
        }
        LL add=1e6;
        LL sub=1e6+1;
        /*DBG(sum,cnt)
            DBG(sub,floor((sub-2)/(a*b-1)),ceil((cnt*sub-sum)/(h*w-cnt)+1e-6))
        while(floor((sub-2)/(a*b-1))<ceil((cnt*sub-sum)/(h*w-cnt)+1e-6)){
            DBG(sub,a*b-1,cnt*sub-sum,h*w-cnt)
            DBG(sub,floor((sub-2)/(a*b-1)),ceil((cnt*sub-sum)/(h*w-cnt)+1e-6))
            sub++;
        }
            DBG(sub,floor((sub-2)/(a*b-1)),ceil((cnt*sub-sum)/(h*w-cnt)+1e-6))
        LL add=floor(sub/(a*b-1));*/
        cout << "Yes"<<"\n";
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                if(i%a==0 and j%b==0)cout << add;
                else if(i%a==h%a and j%b==w%b)cout << -sub;
                else cout << 0;

                if(j<w-1)cout <<' ';
            }
            cout <<"\n";
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

