#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>
#include <numeric>
using namespace std;

typedef long long LL; typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

string res[19];
int cnt,out[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i,19){
        cout<< out[i] <<endl;
        cin >> res[i];
    }

    REP(i,4){
        if(res[i]=="yes"){
            cnt++;
        }
    }
    if(cnt>=2){
        cout<<"composite"<<endl;
        return 0;
    }
    if(cnt==1){
        FOR(i,4,19){
            if(res[i]=="yes"){
                cout<<"composite"<<endl;
                return 0;
            }
        }
    }
    cout << "prime" <<endl;
    return 0;
}
