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
  LL n, s;
  deque<LL> rx, rp, lx, lp;
  Solver(LL n) : n(n), rx(n), rp(n){};

  void solve() {
    cin >> s;
    for (int i = 0; i < n; ++i) {
      cin >> rx[i] >> rp[i];
    }
    while (!rx.empty() and rx[0] < s) {
      lx.push_front(rx.front());
      rx.pop_front();
      lp.push_front(rp.front());
      rp.pop_front();
    }
    LL ans = 0;
    bool l = true;
    LL sum = 0;
    if ((int)rx.size() == 0) {
      cout << abs(s - lx.back()) << "\n";
      return;
    }
    if ((int)lx.size() == 0) {
      cout << abs(s - rx.back()) << "\n";
      return;
    }
    if (lp.back() >= rp.back()) {
      l = true;
      ans += abs(lx.back() - rx.back());
      sum += rp.back();
      rp.pop_back();
      rx.pop_back();
    } else {
      l = false;
      ans += abs(lx.back() - rx.back());
      sum += lp.back();
      lp.pop_back();
      lx.pop_back();
    }
    while (1) {
      if ((int)rx.size() == 0) {
        ans += abs(s - lx.back());
        break;
      }
      if ((int)lx.size() == 0) {
        ans += abs(s - rx.back());
        break;
      }

      if (l) {
        if (rp.back() > lp.back() + sum) {
          l = false;
          ans += abs(lx.back() - rx.back());
          sum += lp.back();
          lp.pop_back();
          lx.pop_back();
        } else {
          l = true;
          sum += rp.back();
          rp.pop_back();
          rx.pop_back();
        }
      } else {
        if (lp.back() >= rp.back() + sum) {
          l = true;
          ans += abs(lx.back() - rx.back());
          sum += rp.back();
          rp.pop_back();
          rx.pop_back();
        } else {
          l = false;
          sum += lp.back();
          lp.pop_back();
          lx.pop_back();
        }
      }
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
