#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

typedef vector<vector<long long >> Matrix;
void multiply(const Matrix &a, const Matrix &b, Matrix &ret){ //ret=a*b
    int k=a.size(),l=a[0].size(),m=b[0].size();
    if(l!=b.size()) DBG("wrong size")
    for(int h=0;h<k;++h){
        for(int i=0;i<m;++i){
            ret[h][i]=0;
            for(int j=0;j<l;j++){
                ret[h][i]+=a[h][j]*b[j][i];
            }
        }
    }
}
//double 行列のrankを掃き出し法で求める。epsの大きさ注意
int sweepout(Matrix &t){
    double eps=1e-8;
    int dig=t.size(),n=t[0].size(),rank=0;
    for(int i=0;i<n;++i){
        int p=rank;
        while(abs(t[p][i])<eps){
            p++;
            if(p==dig) break;
        }
        if(p==dig) continue;
        t[rank].swap(t[p]);
        for(int j=rank+1;j<dig;++j){
            for(int k=i+1;k<n;++k){
                t[j][k]-=t[rank][k]*t[j][i]/t[rank][i];
            }
        }
        rank++;
        if(rank==min(n,dig))break;
    }
    return rank;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    Matrix a(n,vector<long long>(m));

    return 0;
}
