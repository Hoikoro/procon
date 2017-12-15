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
    int h,w,sx,sy;
    vector<vector<short>> board;
    vector<short> vmp;
    Problem(LL h,LL w):h(h),w(w),board (h+1,vector<short>(w+1)),vmp(104060402,-1){};
    int enc(int t,int b, int l, int r){
        return (t*1030301)+(b*10201)+(l*101)+r;
    }
    short getp(int t,int b,int l,int r){
        return board[b][r]-board[b][l-1]-board[t-1][r]+board[t-1][l-1];
    }
    void solve(){
        for(int i=1; i<=h; ++i){
            for(int j=1; j<=w; ++j){
                char tmp;
                cin >> tmp;
                if(tmp=='o') board[i][j]=1;
                else if(tmp=='E'){sx=i;sy=j;}
            }
        }
        for(int i=0; i<=h; ++i){
            for(int j=0; j<w; ++j){
                board[i][j+1]+=board[i][j];
            }
        }
        for(int i=0; i<=w; ++i){
            for(int j=0; j<h; ++j){
                board[j+1][i]+=board[j][i];
            }
        }
        DBG(sx,sy)
        queue<int> Q;
        Q.push(enc(sx,sx,sy,sy));
        vmp[enc(sx,sx,sy,sy)]=0;
        while(!Q.empty()){
            int l,r,t,b,now;
            short nowcnt;
            now=Q.front();
            nowcnt=vmp[now];
            r=(now%101); now/=101;
            l=(now%101); now/=101;
            b=(now%101); now/=101;
            t=now;
            Q.pop();
            int tt=sx-t,bb=b-sx,ll=sy-l,rr=r-sy;
            if(t>1){
                int tmp=enc(t-1,b,l,r);
                if(vmp[tmp]==-1)Q.push(tmp);
                if(t-1>b-sx){
                    vmp[tmp]=max<short>(vmp[tmp],nowcnt+getp(t-1,t-1,max(l,1+rr),min(r,w-ll)));
                }else{
                    vmp[tmp]=max(vmp[tmp],nowcnt);
                }
            DBG(t-1,b,l,r,vmp[tmp],t,b,l,r,nowcnt)
            }
            if(b<h){
                int tmp=enc(t,b+1,l,r);
                if(vmp[tmp]==-1)Q.push(tmp);
                if(sx-t<h-b){
                    vmp[tmp]=max<short>(vmp[tmp],nowcnt+getp(b+1,b+1,max(l,1+rr),min(r,w-ll)));
                }else{
                    vmp[tmp]=max(vmp[tmp],nowcnt);
                }
            DBG(t,b+1,l,r,vmp[tmp],t,b,l,r,nowcnt)
            }
            if(l>1){
                int tmp=enc(t,b,l-1,r);
                if(vmp[tmp]==-1)Q.push(tmp);
                if(l-1>r-sy){
                    vmp[tmp]=max<short>(vmp[tmp],nowcnt+getp(max(t,1+bb),min(b,h-tt),l-1,l-1));
                }else{
                    vmp[tmp]=max(vmp[tmp],nowcnt);
                }
            DBG(t,b,l-1,r,vmp[tmp],t,b,l,r,nowcnt)
            }
            if(r<w){
                int tmp=enc(t,b,l,r+1);
                if(vmp[tmp]==-1)Q.push(tmp);
                if(sy-l<w-r){
                    vmp[tmp]=max<short>(vmp[tmp],nowcnt+getp(max(t,1+bb),min(b,h-tt),r+1,r+1));
                }else{
                    vmp[tmp]=max(vmp[tmp],nowcnt);
                }
            DBG(t,b,l,r+1,vmp[tmp],t,b,l,r,nowcnt)
            }
        }
        cout << vmp[enc(1,h,1,w)] <<"\n";

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long h=0,w;
    cin >> h >> w;
    Problem p(h,w);
    p.solve();
    return 0;
}

