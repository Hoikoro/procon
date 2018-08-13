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
  string s;
  void solve() {
    cin >> s;
    if (s == "zyxwvutsrqponmlkjihgfedcba") {
      cout << -1 << "\n";
    } else if ((int)s.size() < 26) {
      vector<int> cnt(26);
      for (int i = 0; i < (int)s.size(); ++i) {
        cnt[s[i] - 'a']++;
      }
      int ok = -1;
      for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 0) {
          ok = i;
          break;
        }
      }
      s += 'a' + ok;
      cout << s << "\n";
    } else {
      int p = s.size() - 2;
      for (; p >= 0; --p) {
        if (s[p] < s[p + 1]) break;
      }
      vector<int> cnt(26);
      for (int i = 0; i < p; ++i) {
        cnt[s[i] - 'a']++;
      }
      string ans = "";
      for (; p >= 0; --p) {
        int ok = -1;
        for (int i = s[p] - 'a' + 1; i < 26; ++i) {
          if (cnt[i] == 0) {
            ok = i;
            break;
          }
        }
        if (ok > -1) {
          ans = s;
          ans[p] = 'a' + ok;
          ans = ans.substr(0, p + 1);
          break;
        }
      }
      cout << ans << "\n";
    }
  }
};
}  // namespace Problem

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  Problem::Solver sol;
  sol.solve();
  return 0;
}
