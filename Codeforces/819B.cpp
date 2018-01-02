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
    LL n;
    vector<LL> p;
    Problem(LL n):n(n),p(n){};

    void solve(){
        LL ans=0,minsum=LINF,sum=0;
        for(int i=0; i<n; ++i){
            cin >> p[i];
            p[i]--;
        }
        LL inter=ceil(sqrt(n)),div=(n+inter-1)/inter;
        vector<vector<LL>> t(div);
        vector<LL> cnt(div),lpn(div),sub(div);
        for(int i=0; i<n; ++i){
            t[i/inter].push_back(p[i]-i);
            sum+=abs(p[i]-i);
        }
        minsum=sum;
        DBG(minsum)
        for(int i=0; i<div; ++i){
            sort(t[i].begin(),t[i].end());
            cnt[i]=lower_bound(t[i].begin(),t[i].end(),1)-t[i].begin();
            lpn[i]=(cnt[i]==(int)t[i].size()?-1:t[i][cnt[i]]);
        }
        DBG(t)
        for(int i=1; i<n; ++i){//add
            DBG(i)
            for(int j=0; j<div; ++j){
                if((n-i)/inter!=j){
                DBG(j,div)
                    sum+=2*cnt[j]-(int)t[j].size();
                    DBG(sum)
                    sub[j]++;
                    if(lpn[j]==1){
                        while(cnt[j]<(int)t[j].size() and t[j][cnt[j]]<=sub[j]) cnt[j]++;
                        lpn[j]=(cnt[j]==(int)t[j].size()?-1:t[j][cnt[j]]);
                    }else{
                        lpn[j]--;
                    }
                }else{
                    DBG(j,div,2)
                    for(int k=j*inter; k<min((j+1)*inter,n); ++k){
                        sum=sum-abs(p[k]-(k+i-1)%n)+abs(p[k]-(k+i)%n);
                        DBG(sum)
                        /*if(k==n-i){
                            sum=sum-abs(p[k]-n+1)+abs(p[k]);
                        }else{
                            sum=sum-abs(p[k]-(k+i-1)%n)+abs(p[k]-(k+i)%n);
                        }*/
                    }
                    DBG(sum)

                    if((n-i)%inter==0){
                        vector<LL> tmp;
                        for(int k=j*inter; k<min((j+1)*inter,n); ++k){
                            tmp.push_back(p[k]-k+j*inter);
                        }
                        DBG(tmp)
                        sort(tmp.begin(),tmp.end());
                        cnt[j]=lower_bound(tmp.begin(),tmp.end(),1)-tmp.begin();
                        lpn[j]=(cnt[j]==(int)tmp.size()?-1:tmp[cnt[j]]);
                        tmp.swap(t[j]);
                        DBG(t[j])
                        sub[j]=0;
                    }
                }
            }
            if(sum<minsum){
                minsum=sum;
                ans=i;
            }
            DBG(minsum,ans,cnt,lpn,sub)
        }
        cout << minsum << ' '<<ans <<"\n";


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

