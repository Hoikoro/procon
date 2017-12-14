#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;
//Trie
//memory : (total length of strings)*(kinds of letters)
template<int size, class T>
struct Trie{
    T data;
    Trie* parent;
    vector<Trie*> child;
    Trie(Trie *p=nullptr) :data(),parent(p),child(size+1,nullptr){}
    Trie* find(string &s,Trie* now){ //convert charactor to integer in range of [0,size)
        vector<short> res;
        for(int i=0; i<(int)s.size(); ++i)res.push_back(s[i]-'a');
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

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Trie<26,int> p;
    return 0;
}

    /*Trie* erase(Trie* now){
        do{
            for(int i=0; i<size+1; ++i){
                delete now->child[i];
                now->child[i]=nullptr;
            }
            now=now->parent;
        }while(!is_terminated(now));
        for(int i=0; i<size; ++i){
            delete now->child[i];
            now->child[i]=nullptr;
        }
    }*/