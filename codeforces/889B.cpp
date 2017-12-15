#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

struct Problem{
    LL n;
    vector<string> s;
    Problem(LL n):n(n),s(n){};
    void no(){cout << "NO"<<"\n"; exit(0);}
    void solve(){
        for(int i=0; i<n; ++i){
            cin >> s[i];
            string tmp=s[i];
            sort(tmp.begin(),tmp.end());
            tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
            if((int)tmp.size()<(int)s[i].size())no();
        }
        vector<int> prev(26,-1),next(26,-1),used(26,0);
        for(int i=0; i<n; ++i){
            for(int j=0; j<(int)s[i].size(); ++j){
                int c = s[i][j]-'a';
                used[c]=1;
                if(j>0){//prev
                    int d = s[i][j-1]-'a';
                    if(prev[c]==-1 or prev[c]==d){
                        prev[c]=d;
                        if(next[d]>-1 and next[d]!=c)no();
                        next[d]=c;
                    }else no();
                }
                if(j<(int)s[i].size()-1){
                    int d = s[i][j+1]-'a';
                    if(next[c]==-1 or next[c]==d){
                        next[c]=d;
                        if(prev[d]>-1 and prev[d]!=c)no();
                        prev[d]=c;
                    }else no();
                }
            }
        }

        vector<int> head;
        for(int i=0; i<26; ++i){
            if(prev[i]==-1 and used[i]>0)head.push_back(i);
        }
        vector<char> ans;
        for(auto x:head){
            for(int i = x; i!=-1; i=next[i]){
                ans.push_back('a'+i);
            }
        }
        if(accumulate(used.begin(),used.end(),0ll)!=(int)ans.size())no();

        for(auto x:ans)cout<< x;
        cout <<"\n";

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0;
    cin >> n;
    Problem p(n);
    p.solve();
    return 0;
}

