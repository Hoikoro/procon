#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    char field[10][10];
    int uw,lw,ub,lb,answ=8,ansb=8;

    REP(i,8){
        REP(j,8){
            cin >> field[i][j];
        }
    }
    REP(i,8){
        uw=7,lw=0,ub=7,lb=0;
        REP(j,8){
            if(field[j][i]=='B'){
                ub=min(ub,j);
                lb=max(lb,j);
            }
            if(field[j][i]=='W'){
                uw=min(uw,j);
                lw=max(lw,j);
            }
        }
            //cout << ub<< uw<<lb << lw << ansb << answ <<endl;
       if(uw<ub) answ=min(answ,uw);
       if(lb>lw) ansb=min(ansb,7-lb);
    }
            //cout << ansb<< answ<<endl;
    if(answ<=ansb) cout << 'A' << endl;
    else cout << 'B' << endl;
	return 0;
}
