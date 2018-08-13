#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision

#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif

using LL = long long;
constexpr LL LINF = 334ll << 53;
constexpr int INF = 15 << 26;
constexpr LL MOD = 1E9 + 7;

namespace Problem {
using namespace std;

class Solver {
 public:
  LL n;
  vector<LL> a, b;
  vector<set<LL>> aa;
  vector<vector<vector<LL>>> dp;
  vector<int> ok;
  Solver(LL n) : n(n), a(n), b(n), aa(n), dp(51, vector<vector<LL>>(51, vector<LL>(51, -1))), ok(n){};

  void solve() {
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    for (int i = 0; i <= 50; ++i) {
      dp[0][i][i] = 0;
    }
    for (int i = 1; i <= 50; ++i) {
      for (int j = 0; j <= 50; ++j) {
        for (int k = 0; k <= j; ++k) {
          //j->k
          dp[i][j][k] = dp[i - 1][j][k];
          if (dp[i][j][k] == -1) {
            if (dp[i - 1][j % i][k] != -1) {
              dp[i][j][k] = (1ll << i) + dp[i - 1][j % i][k];
            }
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      aa[i].insert(a[i]);
    }
    for (int i = 50; i >= 1; --i) {
      if (!check(i - 1)) {
        ans += (1ll << i);
        for (int j = 0; j < n; ++j) {
          if (aa[j].find(b[j]) == aa[j].end()) {
            if (i == 1 and b[j] != 0) {
              cout << -1 << "\n";
              return;
            }
          }
          set<LL> tmp;
          for (auto x : aa[j]) {
            tmp.insert(x % i);
          }
          for (auto x : tmp) {
            aa[j].insert(x);
          }
        }
      }
    }
    cout << ans << "\n";
  }
  bool check(int x) {
    for (int i = 0; i < n; ++i) {
      bool ok = false;
      for (auto y : aa[i]) {
        if (dp[x][y][b[i]] > -1) ok = true;
      }
      if (!ok) return false;
    }
    return true;
  }
};
}  // namespace Problem

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  long long n = 0;
  std::cin >> n;
  Problem::Solver sol(n);
  sol.solve();
  return 0;
}
