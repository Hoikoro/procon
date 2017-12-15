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

vector<int>n,rem,ans1,ans2;
string s,k;
int dig;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >>s>>k;
    int ls=s.length();
    int ks=k.length();
    if(s=="00"){
        cout << '0' << endl;
        return 0;
    }
    REP(i,ls){
        n.push_back(s.at(i)-'0');
    }
    REP(i,ks){
        rem.push_back(k.at(i)-'0');
    }
    sort(n.begin(),n.end());
    dig=ls-1-(int)log10(ls-(int)log10(ls));
    while(dig>0){
        auto a=lower_bound(n.begin(),n.end(),dig%10);
        n.erase(a);
        dig/=10;
    }

    REP(i,rem.size()){
        auto a=lower_bound(n.begin(),n.end(),rem[i]);
        n.erase(a);
    }
    if(n[0]==0){
        auto a=upper_bound(n.begin(),n.end(),0);
        int tmp=*a;
        if(rem[0]==0){
        n.erase(a);
        n.insert(a,rem.begin(),rem.end());
        n.insert(n.begin(),tmp);
        REP(i,n.size()){
            cout << n[i];
        }
        cout <<endl;
        return 0;
        }else{
            n.erase(a);
            ans1.insert(ans1.begin(),n.begin(),n.end());
            ans1.insert(ans1.begin()+(a-n.begin()),rem.begin(),rem.end());
            ans1.insert(ans1.begin(),tmp);
            ans2.insert(ans2.begin(),n.begin(),n.end());
            ans2.insert(ans2.begin()+(a-n.begin()),tmp);
            ans2.insert(ans2.begin(),rem.begin(),rem.end());
        }
    }else{
        auto a=lower_bound(n.begin(),n.end(),rem[0]);
        ans1.insert(ans1.begin(),n.begin(),n.end());
        ans1.insert(ans1.begin()+(a-n.begin()),rem.begin(),rem.end());
        a=upper_bound(n.begin(),n.end(),rem[0]);
        ans2.insert(ans2.begin(),n.begin(),n.end());
        ans2.insert(ans2.begin()+(a-n.begin()),rem.begin(),rem.end());
    }

        REP(i,ans2.size()){
        cout << ans2[i];
    }
        cout << endl;
            REP(i,ans1.size()){
        cout << ans1[i];
    }
        cout << endl;

    REP(i,ans1.size()){
        if(ans1[i]<ans2[i]){
            REP(i,ans1.size()){
                cout << ans1[i];
            }
            cout << endl;
            return 0;
        }
        if(ans1[i]>ans2[i]){
            REP(i,ans2.size()){
                cout << ans2[i];
            }
            cout << endl;
            return 0;
        }
    }


    REP(i,ans2.size()){
        cout << ans2[i];
    }
        cout << endl;

    return 0;
}
