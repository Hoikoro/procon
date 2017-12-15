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
#define OUT(a) cout<<(a)<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int l=s.length(), dat[200020]={},ans=0;
    REPN(i,1,l){
        if(s[i-1]=='S'){
            dat[i]=dat[i-1]+1;
        }else{
            dat[i]=max(0,dat[i-1]-1);
        }
    }

    REPN(i,1,l){
        if(dat[i-1]==0 and dat[i]==0)ans++;
    }
    cout << ans+dat[l] <<endl;

    return 0;
}
