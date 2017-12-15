#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    char field[11][11]={};
    int line[11]={},col[11]={},tl=0,tc=0;
    int r,c,ans;

    cin >> r >> c;
    REP(i,r){
        REP(j,c){
            cin >> field[i][j];
        }
    }

    REP(i,r){
        REP(j,c){
            if(field[i][j]=='S'){
                line[i]=1;
                col[j]=1;
            }
        }
    }
    REP(i,r){
        tl+=line[i];
    }
    REP(i,c){
        tc+=col[i];
    }
    ans=r*c-tl*tc;

    //cout<< field[0][0] << tl << tc << endl;
	cout << ans << endl;
	return 0;
}
