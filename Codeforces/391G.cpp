#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

string dst__; stringstream dss__;
#define DBG(...) dst__=#__VA_ARGS__;replace(dst__.begin(),dst__.end(),',',' ');dss__.str("");dss__.clear(stringstream::goodbit); dss__<<dst__; debug(dss__,__VA_ARGS__);
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

long long modpow(long long a, long long n){
    long long i=1,ret=1,p=a;
    while(i<n){
        if(i&n) ret=(ret*p)%MOD;
        i=(i<<1);
        p=(p*p)%MOD;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    DBG(modpow(3,1))


    return 0;
}

