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
//emplace_back next_permutation tie get

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define OUT(a) cout<<(a)<<endl;
/*
bool operator> (pair<char,int> &a, pair<char,int> &b){
    return a.first>b.first || (a.first==b.first && a.second<b.second);
}*/

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    bool fin=false;
    int n,l,cnt[26]={},lim=0;
    string s;
    //vector<int> ans;
    vector<pair<char,int>> a,ans,tmp;
    cin >>n >>s;
    l=s.length();
    REP(i,l){
        a.push_back(make_pair(s.at(i),i));
    }
    REP(i,n-1){
        cnt[s.at(i)-'a']++;
    }
    FOR(i,n-1,l){
        cnt[s.at(i)-'a']++;
        int tm;
        REP(j,26){
            if(cnt[j]>0){
                tm=j;
                break;
            }
        }
        cnt[s.at(i+1-n)-'a']--;
        lim=max(lim,tm);
    }
    ans.push_back(make_pair('a',-1));
    REP(i,l){
        if(a[i].first-'a'<=lim) ans.push_back(a[i]);
    }
    ans.push_back(make_pair('a',l));
    auto it=ans.begin()+1;
    while(it<ans.end()-1){
        while(it<ans.end()-1 and (it->first)-'a'==lim and ((it+1)->second - (it-1)->second) <=n){
            ans.erase(it);
        }
        it++;
    }
    //OUT(ans.size())

    ans.erase(ans.begin());
    ans.erase(ans.end()-1);
    sort(ans.begin(),ans.end());
    REP(i,ans.size()){
        cout << ans[i].first;
    }
    cout <<endl;


    return 0;
}
