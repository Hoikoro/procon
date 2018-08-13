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

double eps = 1e-12;
class Solver {
 public:
  int n;
  vector<pair<pair<LL, LL>, LL>> x, y;
  Solver(LL n) : n(n), x(n){};
  void solve() {
    for (int i = 0; i < n; ++i) {
      cin >> x[i].first.first >> x[i].first.second;
      x[i].second = -i;
    }
    y = x;
    sort(x.begin(), x.end());
    vector<pair<pair<LL, int>, LL>> ch(2 * n);
    int k = 0;
    for (int i = 0; i < n; ch[k++] = x[i++]) {
      while (k >= 2 and !ccw(-ch[k - 2].second, -ch[k - 1].second, -x[i].second)) {
        --k;
      }
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = x[i--]) {
      while (k >= t and !ccw(-ch[k - 2].second, -ch[k - 1].second, -x[i].second)) {
        --k;
      }
    }
    ch.resize(k - 1);
    vector<double> ans(n);
    vector<int> ord;
    for (int i = 0; i < (int)ch.size(); ++i) {
      ord.push_back(-ch[i].second);
    }
    ord.push_back(-ch[0].second);
    ord.push_back(-ch[1].second);
    for (int i = 1; i < (int)ord.size() - 1; ++i) {
      ans[ord[i]] = acos_(ord[i - 1], ord[i], ord[i + 1]) / (2.0 * 3.14159265358979);
    }

    for (int i = 0; i < n; ++i) {
      cout << ans[i] << "\n";
    }
  }
  double acos_(int a, int b, int c) {
    LL dx = y[b].first.first - y[a].first.first;
    LL dy = y[b].first.second - y[a].first.second;
    LL nx = y[c].first.first - y[b].first.first;
    LL ny = y[c].first.second - y[b].first.second;
    swap(dx, dy);
    dy = -dy;
    swap(nx, ny);
    ny = -ny;
    double p = dx * dx + dy * dy;
    double q = nx * nx + ny * ny;
    double r = (nx - dx) * (nx - dx) + (ny - dy) * (ny - dy);
    assert(abs((p + q - r) / (sqrt(p) * sqrt(q) * 2.0)) <= 1.0 + eps);
    return acos((p + q - r) / (sqrt(p) * sqrt(q) * 2.0));
  }
  bool cw(int a, int b, int c) {
    LL dx = y[b].first.first - y[a].first.first;
    LL dy = y[b].first.second - y[a].first.second;
    LL nx = y[c].first.first - y[b].first.first;
    LL ny = y[c].first.second - y[b].first.second;
    return dy * nx - dx * ny > 0;
  }
  bool ccw(int a, int b, int c) {
    LL dx = y[b].first.first - y[a].first.first;
    LL dy = y[b].first.second - y[a].first.second;
    LL nx = y[c].first.first - y[b].first.first;
    LL ny = y[c].first.second - y[b].first.second;
    return dy * nx - dx * ny > 0 or (dy * nx - dx * ny == 0 and dx * nx + dy * ny >= 0);
  }
};
}  // namespace Problem

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(10);
  long long n = 0;
  std::cin >> n;
  Problem::Solver sol(n);
  sol.solve();
  return 0;
}
