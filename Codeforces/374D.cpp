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
typedef pair<LL,pair<int,LL>> P;
void answer(priority_queue< P ,vector<P>,greater<P>> &a){
    LL ans[200020]={};
    int n=a.size();
    while(!a.empty()){
        int n=a.size();
        LL f =a.top().first;
        int sf=a.top().second.first;
        LL ss=a.top().second.second;
        a.pop();
        ans[sf]=f*ss;
    }
    REPN(i,1,n-1){
        cout << ans[i]<<' ';
    }
    cout << ans[n] <<endl;
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,k,x,ans[200020]={},frag=1,zero=0;
    cin >> n >> k >> x;
    priority_queue< P ,vector<P>,greater<P>> a;
    REP(i,n){
        LL tmp,z;
        cin  >> tmp;
        if(tmp<0)z=-1;
        else z=1;
        a.push(make_pair(abs(tmp),make_pair(i+1,z)));
        //amin=min(amin,tmp);
        if(tmp<0) frag*=-1;
        else if (tmp==0) ++zero;
    }
        //sort(a.begin(),a.end());
    if(zero==n){
        REP(i,k){
            LL f =a.top().first;
            int sf=a.top().second.first;
            LL ss=a.top().second.second;
            a.pop();
            f+=x;
            if(i==0) ss*=-1;
            a.push(make_pair(f,make_pair(sf,ss)));
        }
        answer(a);
        return 0;
    }

    if(k<zero){
        LL f =a.top().first;
        int sf=a.top().second.first;
        LL ss=a.top().second.second;
        a.pop();
        a.push(make_pair(f+k*x,make_pair(sf,ss)));
        answer(a);
        return 0;
    }
    if(zero ==0 and k*x<=a.top().first and frag == 1){
        //priority_queue< P ,vector<P>,greater<P>> b;
        /*while(a.size()>1){
            LL f =a.top().first;
            int sf=a.top().second.first;
            LL ss=a.top().second.second;
            a.pop();
            b.push(make_pair(f,make_pair(sf,ss)));
        }*/
        LL f =a.top().first;
        int sf=a.top().second.first;
        LL ss=a.top().second.second;
        a.pop();
        a.push(make_pair(f-k*x,make_pair(sf,ss)));
        answer(a);
        return 0;
    }

    if(true){
        LL f =a.top().first;
        int sf=a.top().second.first;
        LL ss=a.top().second.second;
        LL cnt=(f/x)+1;
        //a.pop();
        if(frag==1){
            a.pop();
            a.push(make_pair(cnt*x-f,make_pair(sf,ss*(-1))));
            //answer(a);
            k-=cnt;
        }
        //OUT(cnt)
        REP(i,k){
            LL f =a.top().first;
            int sf=a.top().second.first;
            LL ss=a.top().second.second;
            a.pop();
            a.push(make_pair(f+x,make_pair(sf,ss)));
            //answer(a);
        }
        answer(a);
        return 0;
    }




    return 0;
}
