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
class Writer {
  static ostringstream oss;

 public:
  template <class T>
  void appendln(const vector<vector<T>>& ans, string spl = " ", string el = "\n") {
    for (int i = 0; i < (int)ans.size(); ++i) {
      for (int j = 0; j < (int)ans[i].size(); ++j) {
        oss << ans[i][j];
        oss << (j == (int)ans[i].size() - 1 ? el : spl);
      }
    }
  }
  template <class T>
  void appendln(const vector<T>& ans, string spl = " ") {
    for (int i = 0; i < (int)ans.size(); ++i) {
      oss << ans[i] << (i == (int)ans.size() - 1 ? "\n" : spl);
    }
  }
  template <class T>
  void appendln(const T& answer) { oss << answer << "\n"; }
  template <class T>
  void append(const T& answer) { oss << answer; }
  void appends(const string spl) {
    oss.seekp((int)oss.tellp() - 1);
    oss << "\n";
  }
  template <class F, class... R>
  void appends(const string spl, const F& fi, const R&... rest) {
    oss << fi << spl;
    appends(spl, rest...);
  }
  static void write() { cout << oss.str(); }
  Writer() {
    static bool is_single = true;
    assert(is_single);
    is_single = false;
  };
};
ostringstream Writer::oss;

class Solver {
 public:
  int n;
  Solver(LL n) : n(n){};
  void solve() {
    vector<vector<int>> a(6);
    int sum = 0;
    for (int i = 2; i <= 30000; ++i) {
      int r = i % 6;
      if (r == 0 or r == 2 or r == 3 or r == 4) {
        a[r].push_back(i);
        sum += i;
      }
    }
    if (n < 6) {
      vector<int> ans;
      if (n == 3) ans = {2, 5, 63};
      if (n == 4) ans = {2, 3, 4, 9};
      if (n == 5) ans = {2, 3, 4, 6, 9};
      Writer wr;
      wr.appendln(ans);
    } else {
      int red = 20000 - n;
      int w, x, y, z;
      w = min(1666, red / 3);
      red -= w * 3;
      x = min(1666, red / 3);
      red -= x * 3;
      y = min(2499, red / 2);
      red -= y * 2;
      z = red;
      assert(z <= 5000);
      vector<int> ans;
      for (int i = 0; i < 5000 - w * 3; ++i) {
        ans.push_back(a[2][i]);
      }
      for (int i = 0; i < 5000 - x * 3; ++i) {
        ans.push_back(a[4][i]);
      }
      for (int i = 0; i < 5000 - y * 2; ++i) {
        ans.push_back(a[3][i]);
      }
      for (int i = 0; i < 5000 - z; ++i) {
        ans.push_back(a[0][i]);
      }
      Writer wr;
      wr.appendln(ans);
    }
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
  Problem::Writer::write();
  return 0;
}
