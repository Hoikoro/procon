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
    int h,w;
    vector<vector<char>> b;
    vector<vector<int>> diag;
    Problem(LL h, LL w):h(h),w(w),b (h,vector<char>(w)),diag (h-1,vector<int>(w-1)){};

    //find the rectanble of 1's that has largest area
    //imput[0,1]^(h*w)
    int largest_rectangle2d(vector<vector<int>> &table_){
        vector<vector<int>> table(table_);
        for(int j=0; j<(int)table_[0].size(); ++j){
            int count1 = 0;
            for(int i=0; i<(int)table_.size(); ++i){
                if(table_[i][j]==1)count1++;
                else count1=0;
                table[i][j]=count1;
            }
        }
        int ret = 0;
        for(int i=0; i<(int)table_.size(); ++i){
            ret = max(ret,largest_rectangle(table[i]));
        }
        return ret;
    }

    //find the rectanble in histogram
    //input: histogram (v[i] should be non-negative)
    int largest_rectangle(vector<int> v){
        int ret = 0;
        v.push_back(0);
        stack<pair<int,int>> S;
        S.emplace(0,-1);
        for(int i=0; i<(int)v.size(); ++i){
            if(v[i]>S.top().first) S.emplace(v[i],i);
            else {
                pair<int,int> t;
                while(v[i]<S.top().first){
                    t = S.top();
                    int area = (i-t.second+1)*(t.first+1);
                    ret = max(ret,area);
                    S.pop();
                }
                if(v[i]>S.top().first) S.emplace(v[i],t.second);
            }
        }
        return ret;
    }
    void solve(){
        int ans = max(h,w);
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cin >> b[i][j];
            }
        }
        for(int i=0; i<h-1; ++i){
            for(int j=0; j<w-1; ++j){
                diag[i][j]=(!(b[i][j]==b[i+1][j+1])^(b[i+1][j]==b[i][j+1]));
            }
        }
        cout << max(ans,largest_rectangle2d(diag)) <<"\n";
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long h,w;
    cin >> h >> w;

    Problem p(h,w);
    p.solve();
    return 0;
}

