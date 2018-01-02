#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n;

    cin >> n;
    string tmp;
    int nlet,let[1000],num[26][26]={},ans=0;
    REP(i,n){
        int chk[26]={};
        nlet=0;
        let[0]=0;
        let[1]=0;
        cin >>tmp;
        REP(j,tmp.length()){
            if(chk[tmp.at(j)-'a']==0){
                chk[tmp.at(j)-'a']=1;
                let[nlet]=tmp.at(j)-'a';
                nlet++;
            }
        }
        if(nlet==1){
            REP(j,26){
                num[let[0]][j]+=tmp.length();
                num[j][let[0]]+=tmp.length();
                num[let[0]][let[0]]-=tmp.length();
            }
        }
        if(nlet==2){
            num[let[0]][let[1]]+=tmp.length();
            num[let[1]][let[0]]+=tmp.length();
        }
    }
    REP(i,26){
        REP(j,26){
            ans=max(ans,num[i][j]);
        }
    }
    
	cout << ans<< endl;
	return 0;
}
