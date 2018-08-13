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
  int n;
  vector<string> s;
  Solver(LL n) : n(n), s(n){};

  void solve() {
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    int ans = 0;
    if (check(0, 0)) ans += n;
    for (int i = 1; i < n; ++i) {
      if (check(i, 0)) ans += n - i;
      if (check(0, i)) ans += n - i;
    }
    cout << ans << "\n";
  }
  bool check(int a, int b) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[(i + a) % n][(j + b) % n] != s[(j + a) % n][(i + b) % n]) return false;
      }
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
