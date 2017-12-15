#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,c=0,u=0;
    cin >>n >>m;
    int used[200002]={};
    vector<int> socs(m),ansm(n);
    vector<pair<int,int>> dem(n);
    typedef pair<int,pair<int,int>> PIII;
    priority_queue<PIII,vector<PIII>> sup;
    REP(i,n) {
        int tmp,tmp2=0;
        cin >> tmp;
        dem[i].FI=tmp;
        dem[i].SE=i;
        /*while(true){
            if(tmp<=1000){
                cnd[tmp].PB(MP(tmp2,i));
            }
            if(tmp==1)break;
            tmp=(tmp+1)/2;
            ++tmp2;
        }*/
    }
    REP(i,m){
        int tmp;
        cin >> tmp;
        sup.push(MP(tmp,MP(0,i)));
    }

    //sort(sup.begin(),sup.end(),greater<pair<int,int>>());
    sort(dem.begin(),dem.end(),greater<pair<int,int>>());
    REP(i,n){
        if(!sup.empty()){
            while(sup.top().FI>dem[i].FI){
                int f=sup.top().FI;
                int sf=sup.top().SE.FI;
                int ss=sup.top().SE.SE;
            //cout << f <<' '<<sf<<' '<<ss <<endl;

                sup.pop();
                sup.push(MP((f+1)/2,MP(sf-1,ss)));
            }
            int f=sup.top().FI;
            int sf=sup.top().SE.FI;
            int ss=sup.top().SE.SE;
            //cout << f <<' '<<sf<<' '<<ss <<endl;
            if(f==dem[i].FI){
                socs[ss]=-sf;
                ansm[dem[i].SE]=ss+1;
                used[ss]=1;
                c++;
                u+=-sf;
                sup.pop();
            }else{
                //sup.push(MP((f+1)/2,MP(sf-1,ss)))
            }
        }

    }
    cout <<c <<' ' <<u <<endl;
    REP(i,m-1) cout << socs[i]<<' ';
    cout << socs[m-1]<<endl;
    REP(i,n-1) cout << ansm[i] <<' ';
    cout << ansm[n-1]<<endl;


    return 0;
}
