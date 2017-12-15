#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	//cin.tie(0);
	//ios::sync_with_stdio(false);
    int maxy[110000],filly[110000],edge[220000],n,tm;
    vector<pair<int, int > > ans;
    memset(maxy, -1, sizeof(maxy));
    memset(edge, -1, sizeof(edge));
    memset(filly, -1, sizeof(filly));
    edge[100001]=1;
    edge[99999]=0;
    filly[0]=1;
    scanf("%d",&n);
    REP(i,n){
        int tmp1,tmp2;
        scanf("%d %d",&tmp1,&tmp2);
        maxy[tmp1]=max(maxy[tmp1],tmp2);
   }
   //REP(i,n){cout << maxy[i] << endl;}
   scanf("%d",&tm);
   ans.pb(make_pair(0,0));
   if(tm!=0){
    cout << "NO" << endl;
    return 0;
   }
   REP(i,n-1){
    int wi;
    scanf("%d",&wi);
    if(edge[wi+100000]==-1){
        cout << "NO" << endl;
        return 0;
    }
    ans.pb(make_pair(edge[wi+100000]-wi,edge[wi+100000]));
    if(edge[wi+100000]-wi==0&&edge[wi+100000]<maxy[edge[wi+100000]-wi]){
        edge[wi+100001]=edge[wi+100000]+1;
    }else if(edge[wi+100000]<filly[edge[wi+100000]-wi-1]&&edge[wi+100000]<maxy[edge[wi+100000]-wi]){
        edge[wi+100001]=edge[wi+100000]+1;
    }
    if(edge[wi+100000]==filly[edge[wi+100000]-wi+1]+1&&filly[edge[wi+100000]-wi+1]<maxy[edge[wi+100000]-wi+1]){
        edge[wi+99999]=edge[wi+100000];
    }


    filly[edge[wi+100000]-wi]++;
    edge[wi+100000]=-1;
    //cout << i << ' ' << filly[0]<< endl;
   }
   cout  << "YES" << endl;
   REP(i,n){
    cout << ans[i].first << ' ' << ans[i].second << endl;
   }

	return 0;
}
