#include <bits/stdc++.h>

using LL = long long;

namespace Problem {
using namespace std;

class Solver {
 public:
  int n, k, width, numBlock;
  vector<int> a;
  vector<bitset<5000>> dp;
  Solver(LL n) : n(n){};
  void add(bitset<5000>& dp_, int x) {
    dp_ |= dp_ << x;
  }
  bool unnecessary(bitset<5000>& dp_, int x) {
    for (int i = k - x; i < k; ++i) {
      if (dp_[i] == 1) return false;
    }
    return true;
  }
  void solve() {
    cin >> k;
    for (int i = 0; i < n; ++i) {
      int tmp;
      cin >> tmp;
      if (tmp < k)
        a.push_back(tmp);
    }
    n = a.size();
    width = n / sqrt(n);
    numBlock = (n + width - 1) / width;
    dp.resize(numBlock);
    for (int i = 0; i < dp.size(); ++i) {
      dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < numBlock; ++j) {
        if (i / width == j) continue;
        add(dp[j], a[i]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      auto tmp = dp[i / width];
      for (int j = i / width * width; j < min(n, (i / width + 1) * width); j++) {
        if (j == i) continue;
        add(tmp, a[j]);
      }
      ans += unnecessary(tmp, a[i]);
    }
    cout << ans << endl;
  }
};

}  // namespace Problem

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(12);
  long long n = 0;
  std::cin >> n;

  Problem::Solver sol(n);
  sol.solve();
  return 0;
}
