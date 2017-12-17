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

template<int size, class T>
struct Trie{
    T data;
    Trie* parent;
    vector<Trie*> child;
    Trie(Trie *p=nullptr) :data(),parent(p),child(size+1,nullptr){}
    Trie* find(string &s,Trie* now){ //convert charactor to integer in range of [0,size)
        vector<short> res;
        for(int i=0; i<(int)s.size(); ++i)res.push_back(s[i]-'0');
        return find(res,now);
    }
    template<class S>Trie* find(vector<S> &v, Trie* now){ //find/add nodes
        for(S &s : v){
            if(now->child[s]==nullptr)now->child[s]=new Trie(now);
            now=now->child[s];
        }
        now->child[size]=new Trie(now); //termination
        return now;
    }
    bool terminated(Trie *t){return t->child[size]!=nullptr;}
};

struct Problem{
    LL n,l;
    vector<int> ss,len;
    Trie<2,int> t;
    Problem(LL n, LL l):n(n),l(l),ss(n){};

    void dfs(Trie<2,int>* t, int d){
        for(int i=0; i<2; ++i){
            if(t->child[i]==nullptr)len.push_back(d+1);
            else dfs(t->child[i],d+1);
        }
    }
    void solve(){
        for(int i=0; i<n; ++i){
            string tmp;
            cin >> tmp;
            t.find(tmp,&t);
        }
        dfs(&t,0);
        LL grundy =0;
        for(auto && x:len){
            grundy^=(l-x+1)&(x-l-1);
        }
        if(grundy==0)cout << "Bob"<<"\n";
        else cout << "Alice" <<"\n";


    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n=0,l;
    cin >> n >> l;

    Problem p(n,l);
    p.solve();
    return 0;
}

