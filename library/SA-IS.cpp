#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

//文字列しか引数にできない実装
vector<int> suffixArray(string &s){
    s+=' '; int l=s.size();
    vector<int> ret(l,-1),type(l); // L:0,S:1,LMS:2
    vector<int> cnt(130),press(130,0),bucket(1,0),now;
    type[l-1]=1;
    cnt[s[l-1]-' ']++;
    for(int i=l-2;i>=0;--i){
        cnt[s[i]-' ']++;
        type[i]=(s[i]>s[i+1]?0:(s[i]<s[i+1]?1:type[i+1]));
    }
    for(int i=1; i<l;++i) if(type[i]==1 and type[i-1]==0) type[i]=2;
    int tmp=0;
    for(int i = 0;i<cnt.size();++i){
        if(0!=cnt[i]){
            press[i]=tmp++;
            if(i>0)bucket.push_back(bucket[tmp-2]+cnt[i]);
        }
    }
    copy(bucket.begin(),bucket.end(),back_inserter(now));
    for(int i=0; i<l; ++i){
        if(type[i]==2){
            ret[now[press[s[i]-' ']]]=i;
            --now[press[s[i]-' ']];
        }
    }
    //REP(i,l){cout << i << ' '<<ret[i]<<endl;}
    for(int j=0; j<2; ++j){
        now.clear(); copy(bucket.begin(),bucket.end(),back_inserter(now));
        for(int i=0; i<l; ++i) if(type[ret[i]]!=2) ret[i]=-1;
        for(int i=0; i<l; ++i){
            if( ret[i]>0 and type[ret[i]-1]==0){
                ret[now[press[s[ret[i]-1]-' ']-1]+1]=ret[i]-1;
                ++now[press[s[ret[i]-1]-' ']-1];
            }
        }
        //REP(i,l){cout << i << ' '<<ret[i]<<endl;}
        now.clear(); copy(bucket.begin(),bucket.end(),back_inserter(now));
        for(int i=l-1; i>=0; --i){
            if(ret[i]>0 and type[ret[i]-1]!=0){
                ret[now[press[s[ret[i]-1]-' ']]]=ret[i]-1;
                --now[press[s[ret[i]-1]-' ']];
            }
        }
        //REP(i,l){cout << i << ' '<<ret[i]<<endl;}
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    suffixArray(s);

    return 0;
}
