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

struct Problem{
    int n;
    vector<int> a,cnt;
    Problem(int n):n(n),a(n),cnt(2500){};
    void solve(){
        int k,x;
        cin >> k >> x;
        for(int i=0; i<n; ++i){
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(int j=0; j<k; ++j){
            vector<int> cnt2(2500);
            int sum=-1;
            for(int i=0; i<2050; ++i){
                int op_cnt;
                if(sum==-1 and cnt[i]==0)continue;
                else if(sum==-1) op_cnt=(sum+cnt[i])/2+1;
                else op_cnt=(sum+cnt[i])/2-(sum)/2;
                sum+=cnt[i];
                cnt2[i^x]+=op_cnt;
                cnt2[i]+=cnt[i]-op_cnt;
                //DBG(j,i,cnt[i],sum,op_cnt,i^x)
            }
            cnt=move(cnt2);
        }
        int mini=0,maxi=0;
        for(int i=0; i<(int)cnt.size(); ++i){
            if(cnt[i]>0){
                mini=i;
                break;
            }
        }
        for(int i=(int)cnt.size()-1; i>=0; --i){
            if(cnt[i]>0){
                maxi=i;
                break;
            }
        }
        cout << maxi << ' '<<mini <<"\n";
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    Problem p(n);
    p.solve();
    return 0;
}

