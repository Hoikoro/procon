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

struct SegmentXORTree{
    static const int INIT_VALUE = 0;
    inline int calc(int a,int b){
        return a^b;
    }
    vector<int> data;
    int n;
    explicit SegmentXORTree(int _n){
        n = 1;
        while(n < _n) n *= 2;
        data = vector<int>(2*n-1,0);
    }

    void update(int i,int v){
        int k = i + n-1;
        data[k] = v;
        while(k > 0){
            k = parent(k);
            data[k] = calc(data[get_left(k)],data[get_right(k)]);
        }
    }

    inline int get(int a,int b){
        return get(a,b,0,0,n);
    }
private:
    int get(int a,int b,int k,int l,int r){
        if(r <= a or b <= l) return 0;
        if(a <= l and r <= b) return data[k];
        int vl = get(a,b,get_left(k),l,(l+r)/2);
        int vr = get(a,b,get_right(k),(l+r)/2,r);
        return calc(vl,vr);
    }

    inline int get_left(int x){
        return 2*x+1;
    }
    inline int get_right(int x){
        return 2*x+2;
    }
    inline int parent(int x){
        return (x-1)/2;
    }
};
struct SegmentSUMTree{
    static const int INIT_VALUE = 0;
    inline int calc(int a,int b){
        return a+b;
    }
    vector<int> data;
    int n;
    explicit SegmentSUMTree(int _n){
        n = 1;
        while(n < _n) n *= 2;
        data = vector<int>(2*n-1,0);
    }

    void update(int i,int v){
        int k = i + n-1;
        data[k] = v;
        while(k > 0){
            k = parent(k);
            data[k] = calc(data[get_left(k)],data[get_right(k)]);
        }
    }

    inline int get(int a,int b){
        return get(a,b,0,0,n);
    }
private:
    int get(int a,int b,int k,int l,int r){
        if(r <= a or b <= l) return 0;
        if(a <= l and r <= b) return data[k];
        int vl = get(a,b,get_left(k),l,(l+r)/2);
        int vr = get(a,b,get_right(k),(l+r)/2,r);
        return calc(vl,vr);
    }

    inline int get_left(int x){
        return 2*x+1;
    }
    inline int get_right(int x){
        return 2*x+2;
    }
    inline int parent(int x){
        return (x-1)/2;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >>n;
    SegmentXORTree a(n);
    SegmentSUMTree b(n);
    REP(i,n){
        int tmp;
        cin >> tmp;
        a.update(i,tmp);
        b.update(i,tmp);
    }
    cin >> m;
    REP(i,m){
        int l,r;
        cin>>l>>r;
        cout<< a.get(l-1,r) <<endl;
        cout<< b.get(l-1,r) <<endl;

    }

    return 0;
}
