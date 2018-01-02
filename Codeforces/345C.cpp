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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,tmp1,tmp2;
    LL ans=0;
    cin >>n;
    vector<int> x(n),y(n),x1(n),y1(n);
    vector<pair<int,int>> p;

    REP(i,n){
        cin >> tmp1 >> tmp2;
        x[i]=tmp1;
        y[i]=tmp2;
        p.push_back(MP(tmp1,tmp2));
    }
    x1.insert(x1.end(),x.begin(),x.end());
    y1.insert(y1.end(),y.begin(),y.end());
    sort(x1.begin(),x1.end());
    sort(y1.begin(),y1.end());
    x1.erase(unique(x1.begin(),x1.end()),x1.end());
    y1.erase(unique(y1.begin(),y1.end()),y1.end());
    REP(i,n){
        x[i]=lower_bound(x1.begin(),x1.end(),x[i])-x1.begin();
        y[i]=lower_bound(y1.begin(),y1.end(),y[i])-y1.begin();
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    REP(i,x1.size()){
        auto range=equal_range(x.begin(),x.end(),i);
        tmp1=range.second-range.first;
        ans+=(LL)tmp1*(tmp1-1)/2;
    }
    REP(i,y1.size()){
        auto range=equal_range(y.begin(),y.end(),i);
        tmp1=range.second-range.first;
        ans+=(LL)tmp1*(tmp1-1)/2;
    }
    sort(p.begin(),p.end());
    tmp1=1;
    FOR(i,1,p.size()){
        if(p[i-1]==p[i]){
            tmp1++;
        }else{
            ans-=(LL)tmp1*(tmp1-1)/2;
            tmp1=1;
        }
    }
    ans-=(LL)tmp1*(tmp1-1)/2;
    cout<< ans << endl;

    return 0;
}
