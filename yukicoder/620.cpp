#include <bits/stdc++.h>
using namespace std;
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

#if MYDEBUG
#include "lib/cp_debug.h"
#else
#define DBG(...) ;
#endif

using LL = long long;
using Matrix = vector<vector<double>>;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;


struct Problem{
    int t;
    double w,v,gx,gy,p;
    vector<vector<vector<double>>> mat;
    vector<vector<double>> coeff;
    vector<vector<double>> ans;
    Problem(int t):t(t),mat (t+1,vector<vector<double>>(2,vector<double>(2))),coeff (2*t+2,vector<double>(2*(2*t+2))),ans (2*t+2,vector<double>(1)){};
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
    int sweepout(Matrix &t){
        double eps=1e-8;
        int dig=t.size(),n=t[0].size(),rank=0;
        for(int i=0;i<n;++i){
            int p=rank;
            while(abs(t[p][i])<eps){
                p++;
                if(p==dig) break;
            }
            if(p==dig) return -1;
            t[rank].swap(t[p]);
            for(int k=i+1; k<n; ++k){
                t[rank][k]/=t[rank][i];
            }
            t[rank][i]=1;
            for(int j=rank+1;j<dig;++j){
                for(int k=i+1;k<n;++k){
                    t[j][k]-=t[rank][k]*t[j][i]/t[rank][i];
                }
                t[j][i]=0;
            }
            rank++;
            if(rank==min(n,dig))break;
        }
        for(int j=dig-1; j>=0; --j){
            for(int i=0; i<j; ++i){
                for(int k=j+1; k<n; ++k){
                    t[i][k]-=t[j][k]*t[i][j];
                }
            }
        }
        return rank;
    }
    void solve(){
        cin >> p >> w >> v >> gx >> gy;
        mat[0]={{1,0},{0,1}};
        mat[1]={{v+1,-w},{w,v+1}};
        //mat =(v+1 -w )
        //     ( w  v+1)
        for(int i=2; i<=t; ++i){
            for(int j=0; j<2; ++j){
                for(int k=0; k<2; ++k){
                    for(int l=0; l<2; ++l){
                        mat[i][j][k]+=mat[i-1][j][l]*mat[1][l][k];
                    }
                }
            }
        }
        double dx,dy;
        dx = gx-mat[t][0][0];
        dy = gy-mat[t][1][0];
        for(int i=0; i<2*t+2; ++i){
            coeff[i][i+2*t+2]=1;
        }
        vector<double> c1(2*t+1),c2(2*t+1);
        for(int i=0; i<t; ++i){
            c1[i]=mat[t-1-i][0][0];
            c1[i+t]=mat[t-1-i][0][1];
        }
        c1[2*t]=-dx;
        for(int i=0; i<t; ++i){
            c2[i]=mat[t-1-i][1][0];
            c2[i+t]=mat[t-1-i][1][1];
        }
        c2[2*t]=-dy;

        //Minimize x_0^2+...x_{t-1}^2 + y_0^2+...y_{t-1}^2
        //subject to (dx dy)^T=\sum_{i=0}^(t-1) (mat)^(t-1-i)(u_{x,i} u_{y,i})^T
        //を未定乗数法で解く.　(偏微分)=0が(2*t+2)変数の線形方程式になる．

        vector<vector<double>> rhs (2*t+2,vector<double>(1));
        for(int i=0; i<2*t; ++i){
            coeff[i][i]=2;
            coeff[i][2*t]=-c1[i];
            coeff[i][2*t+1]=-c2[i];
            coeff[2*t][i]=-c1[i];
            coeff[2*t+1][i]=-c2[i];
        }
        rhs[2*t][0]=c1[2*t];
        rhs[2*t+1][0]=c2[2*t];

        sweepout(coeff);
        vector<vector<double>> inv (2*t+2,vector<double>(2*t+2));
        for(int i=0; i<2*t+2; ++i){
            for(int j=0; j<2*t+2; ++j){
                inv[i][j]=coeff[i][j+2*t+2];
            }
        }
        multiply(inv,rhs,ans);
        for(int i=0; i<t; ++i){
            cout << ans[i][0] <<' ' <<ans[i+t][0]<<"\n";
        }
        //check
        double square_sum =0,nx =1,ny =0;
        for(int i=1; i<=t; ++i){
            square_sum+=ans[i][0]*ans[i][0]+ans[i+t][0]*ans[i+t][0];
            double tmp = nx;
            nx = (v+1)*nx -w*ny +ans[i-1][0];
            ny = (v+1)*ny +w*tmp+ans[i+t-1][0];
        }
        DBG(square_sum)
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed <<setprecision(40) <<"\n";
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        int t;
        cin >> t;
        Problem p(t);
        p.solve();
    }
    return 0;
}

