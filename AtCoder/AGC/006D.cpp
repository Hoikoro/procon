#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

string dst__; stringstream dss__;
#define DBG(...) dst__=#__VA_ARGS__;replace(dst__.begin(),dst__.end(),',',' ');dss__.str("");dss__.clear(stringstream::goodbit); dss__<<dst__; debug(dss__,__VA_ARGS__);
inline void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}

typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
typedef pair<int,int>PI; typedef vector<int> VI;
constexpr LL LINF=334ll<<53; constexpr int INF=15<<26; constexpr LL MOD=1E9+7;

int comp(VI &a, int pos, int s){
    if((a[pos-1]<=s and a[pos]<= s) or (a[pos]<=s and a[pos+1]<=s)) return 1;
    if((a[pos-1]>s and a[pos]>s) or (a[pos]>s and a[pos+1]>s)) return -1;
    return 0;
}

bool check(int s, VI &a){
    int n=((int)a.size()+1)/2;
    for(int i=0; i<n; i+=1){
        int p=comp(a,n-1+i,s),q=comp(a,n-1-i,s);
        if(p==1 or q==1) return true;
        if(p==-1 or q==-1) return false;
    }
    int res=0;
    if(a[0]<=s)++res;
    if(a[n-1]<=s)++res;
    if(a[a.size()-1]<=s)++res;
    return res>=2;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    VI a(2*n-1);
    for(int i=0; i<2*n-1; ++i){
        cin >> a[i];
    }
    int l=0, u=2*n;
    while(u-l>1){
        int mid=(l+u)/2;
        if(check(mid,a))u=mid;
        else l=mid;
    }

    cout << u << "\n";
    return 0;
}

