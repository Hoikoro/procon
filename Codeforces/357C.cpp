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
priority_queue<int, vector<int>,greater<int>> a;
int n,tmp;
vector<pair<string , int >> ans;
string qry;
int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    cin >> n;
    REP(i,n){
        cin >> qry;
        if(qry=="insert"){
            scanf("%d",&tmp);
            a.push(tmp);
            ans.push_back(make_pair(qry,tmp));
        }else if(qry=="removeMin"){
            if(!a.empty()){
                a.pop();
                ans.push_back(make_pair(qry,0));
            }else{
                ans.push_back(make_pair("insert",1));
                ans.push_back(make_pair(qry,0));
            }
        }else if(qry=="getMin"){
            scanf("%d",&tmp);
            while(!a.empty()&&a.top()<tmp){
                a.pop();
                ans.push_back(make_pair("removeMin",0));
            }
            if(!a.empty()&&a.top()==tmp){
                ans.push_back(make_pair("getMin",tmp));
            }else{
                a.push(tmp);
                ans.push_back(make_pair("insert",tmp));
                ans.push_back(make_pair("getMin",tmp));
            }
        }else{
            OUT("?")
            return 0;
        }
        //OUT(a.size())
    }
    int sz=ans.size();
    cout <<sz<<endl;
    REP(i,sz){
        if(ans[i].first=="removeMin"){
            printf("%s\n",ans[i].first.c_str());
        }else{
            printf("%s %d\n",ans[i].first.c_str(),ans[i].second);
        }
    }

    return 0;
}
