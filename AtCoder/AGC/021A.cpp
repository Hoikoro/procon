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
  Solver(LL n) : n(n){};

  void solve() {
    int ans = digsum(n);
    LL k = 1e16;
    LL m = 0;
    while (k > 0) {
      while (m + k <= n + 1) m += k;
      ans = max(ans, digsum(m - 1));
      k /= 10;
    }
    cout << ans << "\n";
  }
  int digsum(LL a) {
    int ret = 0;
    while (a > 0) {
      ret += a % 10;
      a /= 10;
    }
    return ret;
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
