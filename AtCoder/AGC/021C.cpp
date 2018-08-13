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
  LL n, m, a, b;
  void solve() {
    cin >> n >> m >> a >> b;
    if ((a + b) * 2 != n * m) {
      cout << "NO" << endl;
      return;
    }
    if (n % 2 == 0 and m % 2 == 0) {
      if (a % 2 == 1 or b % 2 == 1)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
      return;
    } else {
      if (n % 2 == 0) swap(n, m);
    }
  }
};
}  // namespace Problem

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  long long n = 0;
  Problem::Solver sol;
  sol.solve();
  return 0;
}
