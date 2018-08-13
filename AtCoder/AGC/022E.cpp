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

template <long long Mod = MOD>
struct Modint {
 public:
  //long long Mod = MOD;
  long long v;
  template <typename T>
  Modint(T x) {
    x %= Mod;
    long long y = (long long)x;
    if (y < 0) y += Mod;
    v = y;
  }
  Modint() : v(0) {}
  Modint &operator+=(Modint a) {
    v = (v + a.v);
    if (v >= Mod) v -= Mod;
    return *this;
  }
  Modint &operator-=(Modint a) {
    v = (v - a.v);
    if (v < 0) v += Mod;
    return *this;
  }
  Modint &operator*=(Modint a) {
    v = (v * a.v) % Mod;
    return *this;
  }
  Modint &operator/=(Modint a) {
    v = (v * a.mpow(Mod - 2).v) % Mod;
    return *this;
  }
  Modint mpow(Modint n) { return mpow(n.v); }
  Modint mpow(long long n) {
    long long i = 1, p = v;
    Modint ret(1);
    while (i <= n) {
      if (i & n) ret *= p;
      i = (i << 1);
      p = (p * p) % Mod;
    }
    return ret;
  }
  Modint operator+(Modint a) {
    long long t = (v) + (a.v);
    return Modint(t);
  }
  Modint operator-(Modint a) {
    long long t = (v) - (a.v);
    return Modint(t);
  }
  Modint operator*(Modint a) {
    long long t = (v) * (a.v);
    return Modint(t);
  }
  Modint operator/(Modint a) {
    return a.mpow(Mod - 2) * *this;
  }
};
template <long long M>
ostream &operator<<(ostream &os, const Modint<M> m) {
  return os << m.v;
}
class Solver {
 public:
  string s;
  int n;
  vector<Modint<>> fac, inv;
  Solver() : fac(330000), inv(330000) {
    cin >> s;
    n = (int)s.size();
    fac[0] = 1;
    for (int i = 1; i < (int)fac.size(); ++i) {
      fac[i] = fac[i - 1] * i;
    }
    inv.back() = fac.back().mpow(MOD - 2);
    for (int i = (int)inv.size() - 2; i >= 0; --i) {
      inv[i] = inv[i + 1] * (i + 1);
    }
  }

  void solve() {
    Modint<> ans;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '?') cnt++;
    }
    if (n == 1) {
      cout << 1 << "\n";
    } else if (s[0] == '1' and s[n - 1] == '1') {
      ans = 2;
      ans = ans.mpow(cnt);
      cout << ans << "\n";
    } else if (s[0] == '?' and s[n - 1] == '1') {
      s[0] = '0';
      ans = 2;
      ans = ans.mpow(cnt - 1);
      ans += calc(s, cnt - 1);
      cout << ans << "\n";
    } else if (s[0] == '1' and s[n - 1] == '?') {
      s[n - 1] = '0';
      ans = 2;
      ans = ans.mpow(cnt - 1);
      ans += calc(s, cnt - 1);
      cout << ans << "\n";
    } else if (s[0] == '?' and s[n - 1] == '?') {
      ans = 2;
      ans = ans.mpow(cnt - 2);
      auto t = s;
      t[0] = '1';
      t[n - 1] = '0';
      ans += calc(t, cnt - 2);
      t = s;
      t[0] = '0';
      t[n - 1] = '1';
      ans += calc(t, cnt - 2);
      t = s;
      t[0] = '0';
      t[n - 1] = '0';
      ans += calc(t, cnt - 2);
      cout << ans << "\n";
    } else {
      ans = calc(s, cnt);
      cout << ans << "\n";
    }
  }
  Modint<> calc(string s, int cnt) {
    Modint<> ret = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != '?') continue;
      bool adj = false;
      if (i > 0 and s[i - 1] == '1') adj = true;
      if (i < n - 1 and s[i + 1] == '1') adj = true;
      if (adj) {
        s[i] = '0';
        ret += Modint<>(2).mpow(cnt - 1);
        cnt--;
      }
    }
    Modint<> tmp = 1;
    int sc = 0;
    for (int i = 0; i <= n; ++i) {
      if (i < n and s[i] == '?') {
        sc++;
      } else {
        if (sc > 0) {
          Modint<> tmp2 = 0;
          for (int j = 0; j <= (sc + 1) / 2; ++j) {
            tmp2 += fac[sc - j + 1] * inv[j] * inv[sc - j * 2 + 1];
          }
          tmp *= tmp2;
        }
        sc = 0;
      }
    }
    return ret + Modint<>(2).mpow(cnt) - tmp;
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
