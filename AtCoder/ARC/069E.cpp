#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first

#if MYDEBUG
#define DBG(...) {string dst__=#__VA_ARGS__;dbgsplit(dst__);stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
#else
#define DBG(...)
#endif
void debug(stringstream& ds){cerr<<endl;return;}
template<typename F, typename... R>void debug(stringstream& ds,const F& f, const R&... r){string n; ds>>n; cerr<< n <<'='<<f<<' '; debug(ds,r...);}
void dbgsplit(string &s){int l=s.length(),n=0;for(int i=0; i<l; ++i){if(s[i]=='(')++n;if(s[i]==')')--n;if(s[i]==','&&!n)s[i]=' ';}}
using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    LL n;
    cin >> n;
    vector<tuple<LL,LL,LL>> a;
    vector<LL> ans(n);
    for(int i=0; i<n; ++i){
        LL tmp;
        cin >>tmp;
        a.emplace_back(tmp,i,0);
    }
    sort(a.begin(),a.end());
    map<LL,LL> cnt,lb;
    LL rb=n,l=n-1;
    for(int i=n-1; i>0;--i){
        if(get<0>(a[i])>get<0>(a[i-1])){
            cnt[get<0>(a[i])]=rb-i;
            rb=i;
            l=min(l,get<1>(a[i]));
            lb[get<0>(a[i])]=l;
        }
    }
    cnt[get<0>(a[0])]=rb;
    lb[get<0>(a[0])]=0;
    LL cntsum=0;
    for(int i=n-1; i>0; --i){
        if(get<0>(a[i-1]) < get<0>(a[i])){
            LL pos,num,sum;
            tie(num,pos,sum)=a[i];
            cntsum+=cnt[num];
    DBG(num,cnt[num],cntsum,lb[num])
            ans[lb[num]]+=cntsum*(num-get<0>(a[i-1]));
        }
    }
    LL pos,num,sum;
    tie(num,pos,sum)=a[0];
    cntsum+=cnt[num];
    DBG(num,cnt[num],cntsum)
    assert(cntsum==n);
    ans[lb[num]]+=cntsum*num;
    for(int i=0; i<n; ++i){
        cout << ans[i]<<"\n";
    }

    return 0;
}

