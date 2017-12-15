#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

typedef long long LL;
#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define OUT(a) cout<<(a)<<endl;

string s;
int n[27];
bool check(){
    REP(i,26){
        if(n[i]>1){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    int l=s.length();
    if(l<26){
        cout << -1 << endl;
        return 0;
    }
    REP(i,25){
        if(s[i]=='?'){
            n[26]++;
        }else{
            n[s[i]-'A']++;
        }
    }
    FOR(i,25,l){
        if(s[i]=='?'){
            n[26]++;
        }else{
            n[s[i]-'A']++;
        }
        if(check()){
            while(n[26]>0){
                int it=0,p=0;
                while(n[it]!=0) it++;
                while(s[p+i-25]!='?') p++;
                s[p+i-25]='A'+it;
                n[it]=1;
                n[26]--;
            }
            string::size_type pos = s.find("?");
            while(pos != string::npos){
                s.replace(pos, 1, "A");
                pos = s.find("?", pos + 1);
                //cout << s <<endl;
            }

            cout << s << endl;
            return 0;
        }
        if(s[i-25]=='?'){
            n[26]--;
        }else{
            n[s[i-25]-'A']--;
        }

    }
    cout << -1 << endl;
    return 0;
}
