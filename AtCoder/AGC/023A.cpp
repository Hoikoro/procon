#include <bits/stdc++.h>
// make_tuple emplace_back next_permutation push_back make_pair second first
// setprecision

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
  vector<LL> a;
  Solver(LL n) : n(n), a(n){};

  void solve() {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
      a[i] += a[i - 1];
    }
    map<LL, LL> m;
    for (int i = 0; i < n; ++i) {
      m[a[i]]++;
    }
    m[0]++;
    LL ans = 0;
    for (auto x : m) {
      ans += (x.second - 1) * x.second / 2;
    }
    cout << ans << "\n";
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
