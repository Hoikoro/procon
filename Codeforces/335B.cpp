#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <list>
#include <set>

#define REP(i,n) for(int (i)=0; (i)<(n) ;(i)++)
#define REPP(i,n) for(int (i)=1; (i)<=(n) ;(i)++)
#define pb push_back

using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int x,y,posx,posy,ans,reach[550][550]={};
    cout << 1<<' ';
    string c;
    cin >>x >> y >> posx >> posy;
    reach[posx][posy]=1;
    cin >>c;
    REP(i,c.length()){
        bool b=false;
        if(c.at(i)=='U'){
            if(posx>1) posx--;
            else b=true;
        }
        if(c.at(i)=='D'){
            if(posx<x) posx++;
            else b=true;
        }
        if(c.at(i)=='L'){
            if(posy>1) posy--;
            else b=true;
        }
        if(c.at(i)=='R'){
            if(posy<y) posy++;
            else b=true;
        }
        if(i==c.length()-1){
            if(b==false) {cout << x*y-ans-1<<endl;}
            else{cout << x*y-ans-1<<endl;}
        }else if(b==false) {
            cout << 1-reach[posx][posy]<<' ';
            ans+=1-reach[posx][posy];
            reach[posx][posy]=1;
        }else{cout <<0 << ' ';}
    }

	//cout << x*y-ans << endl;
	return 0;
}
