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
#include <bitset>
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
    int q; cin >> q;
    vector<int> s;
    s.push_back(0);
    REP(i,q){
        char a; int b;
        cin >> a >> b;
        if(a=='+'){
            s.insert(upper_bound(s.begin(),s.end(),b),b);
        }
        if(a=='-'){
            if(upper_bound(s.begin(),s.end(),b)-lower_bound(s.begin(),s.end(),b)>0){
                s.erase(lower_bound(s.begin(),s.end(),b));
            }
        }
        if(a=='?'){
            bitset<30> bs(b);
            int l=0,u=1<<30,ans=0;
            REP(j,30){
                //OUT(j)
                //OUT(u)
                //OUT(l)
                if(!bs[29-j]){
                    //OUT(1)
                    int m=(l+u)/2;
                    if(lower_bound(s.begin(),s.end(),u)-lower_bound(s.begin(),s.end(),m)>0){
                        ans+=1<<(29-j);
                        l=m;
                    }else{
                        u=m;
                    }
                }else{
                    int m=(l+u)/2;
                    if(lower_bound(s.begin(),s.end(),m)-lower_bound(s.begin(),s.end(),l)>0){
                        ans+=1<<(29-j);
                        u=m;
                    }else{
                        l=m;
                    }
                }
                //OUT(ans)
                //cout << endl;
            }
        cout << ans << endl;
        }
    }
    return 0;
}
