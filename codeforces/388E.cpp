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
#include <random>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define dump(a) cerr<<#a <<' '<< a <<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

struct BIT{
    vector<double> bit;
    int size;
    BIT(int _size) : bit(vector<double>(_size+1,0)),size(_size){}
    void add(int index, double value){
        for(int i=index+1 ; i<=size ; i+=(i&-i)) bit[i]+=value;
    }
    double sum(int a,int b){//sum of[a,b)
        return sum(b)-sum(a);
    }
    double sum(int a){ // sum of[0,a) = sum of bit[0]~bit[a]
        double ret=0;
        for(int i= a ; i>0; i-=(i&-i)) ret+=bit[i];
        return ret;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> pos(n+1);
    REP(i,n){
        int a;cin >> a;
        pos[a]=i+1;
    }
    BIT cnt(n+1),sum(n+1);
    double su=0.0,prd=0.0;
    FOR(i,1,n){
        su+=(double)pos[i]-1.0-cnt.sum(1,pos[i]);
        su-=((double)n-pos[i]-cnt.sum(pos[i]+1,n+1));
        prd+=((double)pos[i]*(pos[i]-1)/2-sum.sum(1,pos[i]))*(n+1-pos[i]);
        prd-=(double)pos[i]*((double)(n+1)*((double)n-pos[i]-cnt.sum(pos[i]+1,n+1))-((double)pos[i]+1+n)*(n-pos[i])/2+sum.sum(pos[i]+1,n+1));
        cnt.add(pos[i],1);
        sum.add(pos[i],pos[i]);

    }
    cout << fixed << setprecision(10) <<(double)n*(n-1.0)/4.0+su/2-prd/((double)n*(n+1)) <<endl;

    return 0;
}
