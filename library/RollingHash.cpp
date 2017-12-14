#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

//数列{a_1,...,a_n}を\sum_{i=1}^n a_ib^i (mod p)に変換する。
//pとして10^9に近い素数を3つ用いる、bを1~10^7の範囲で一様ランダムに選択するといった方法でハッシュの衝突確率が下がる。　ただし3倍重い。
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >>q;
    vector<vector<LL>> h(n+1,vector<LL>(3));
    map<vector<LL>,int> m;
    random_device rand;
    mt19937 mt(rand());
    uniform_int_distribution<LL> dist(1, 1e7);
    LL b[3]={dist(mt),dist(mt),dist(mt)},p[3]={999999937,MOD,MOD+2};
    h[0]={0,0,0};
    h[1]={1,1,1};
    for(int i=2; i<n+1; ++i){
        for(int j=0; j<3; ++j){
            h[i][j]=h[i-1][j]*b[j]%p[j];
        }
    }
    for(int i=2; i<n+1; ++i){
        for(int j=0; j<3; ++j){
            h[i][j]=(h[i][j]+h[i-1][j])%p[j];
        }
    }


    return 0;
}
