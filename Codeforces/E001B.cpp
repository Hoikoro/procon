#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back


using namespace std;
int main(){
	//cin.tie(0);
	//ios::sync_with_stdio(false);

    string s;
    int m;
    vector<int> pos;
    cin >> s;
    cin >>m;
    REP(i,s.size()){
        pos.pb(i);
    }
    REP(i,m){
        int l,r,k;
        cin >> l >> r >> k;
        if((r!=l)&&(k%(r-l+1)!=0)){
            vector<int> tmp(pos.begin()+r-(k%(r-l+1)),pos.begin()+r);
            pos.erase(pos.begin()+r-(k%(r-l+1)),pos.begin()+r);
            pos.insert(pos.begin()+l-1,tmp.begin(),tmp.end());
            tmp.clear();
        }
            //REP(i,s.size()) cout<< pos[i];
    }

    REP(i,s.size()) printf("%c",s[pos[i]]);
    printf("\n");
	//cout <<  << endl;
	return 0;
}
