#include <bits/stdc++.h>

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
class Modint {
 public:
  long long v;

  Modint(const Modint &x) { v = x.v; }
  explicit Modint(int x) {
    if (x < 0 or Mod <= x) x %= Mod;
    if (x < 0) x += Mod;
    v = x;
  }
  explicit Modint(long long x) {
    if (x < 0 or Mod <= x) x %= Mod;
    if (x < 0) x += Mod;
    v = x;
  }
  explicit Modint(unsigned x) {
    if (Mod <= x) x %= Mod;
    v = x;
  }
  explicit Modint(unsigned long long x) {
    if (Mod <= x) x %= Mod;
    v = x;
  }
  template <typename T>
  explicit Modint(T x) {
    if (x < 0 or Mod <= x) x %= Mod;
    v = x;
  }
  Modint() : v(0) {}
  long long get() const { return v; }
  Modint mpow(Modint &n) const { return mpow(n.v); }
  Modint mpow(long long n) const {
    long long i = 1, p = v;
    Modint ret(1);
    while (i <= n) {
      if (i & n) ret *= p;
      i = (i << 1);
      p = (p * p) % Mod;
    }
    return ret;
  }
  Modint operator-() const { return (v ? Modint(Mod - v) : Modint(0)); }
  explicit operator int() const { return v; }
  explicit operator long long() const { return v; }
  Modint &operator+=(const Modint &a) {
    v = (v + a.v);
    if (v >= Mod) v -= Mod;
    return *this;
  }
  Modint &operator-=(const Modint &a) {
    v = (v - a.v);
    if (v < 0) v += Mod;
    return *this;
  }
  Modint &operator*=(const Modint &a) {
    v = (v * a.v) % Mod;
    return *this;
  }
  Modint &operator/=(const Modint &a) {
    v = (v * a.mpow(Mod - 2).v) % Mod;
    return *this;
  }
  template <class T>
  Modint &operator+=(const T &a) {
    v = (v + Modint(a).v);
    if (v >= Mod) v -= Mod;
    return *this;
  }
  template <class T>
  Modint &operator-=(const T &a) {
    v = (v - Modint(a).v);
    if (v < 0) v += Mod;
    return *this;
  }
  template <class T>
  Modint &operator*=(const T &a) {
    v = (v * Modint(a).v) % Mod;
    return *this;
  }
  template <class T>
  Modint &operator/=(const T &a) {
    v = (v * Modint(a).mpow(Mod - 2).v) % Mod;
    return *this;
  }
  friend Modint operator+(const Modint &a, const Modint &b) {
    return Modint(a) += b;
  }
  friend Modint operator-(const Modint &a, const Modint &b) {
    return Modint(a) -= b;
  }
  friend Modint operator*(const Modint &a, const Modint &b) {
    return Modint(a) *= b;
  }
  friend Modint operator/(const Modint &a, const Modint &b) {
    return Modint(a) /= b;
  }
  template <class T, class U>
  friend Modint operator+(const T &a, const U &b) {
    return Modint(a) += Modint(b);
  }
  template <class T, class U>
  friend Modint operator-(const T &a, const U &b) {
    return Modint(a) -= Modint(b);
  }
  template <class T, class U>
  friend Modint operator*(const T &a, const U &b) {
    return Modint(a) *= Modint(b);
  }
  template <class T, class U>
  friend Modint operator/(const T &a, const U &b) {
    return Modint(a) /= Modint(b);
  }
};

template <long long M>
ostream &operator<<(ostream &os, const Modint<M> m) {
  return os << m.v;
}
template <long long Mod = MOD>
class Factorial {
 public:
  int n;
  Factorial(long long n) : n(n), fac(n + 1), inv(n + 1) {
    fac[0] = 1;
    for (int i = 0; i < n; ++i) fac[i + 1] = fac[i] * (i + 1) % Mod;
    inv[n] = modpow(fac[n], Mod - 2);
    for (int i = n - 1; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % Mod;
  };
  long long modpow(long long a, long long n, long long mod = Mod) {
    long long i = 1, ret = 1, p = a;
    while (i <= n) {
      if (i & n) {
        ret = (ret * p) % mod;
      }
      i = (i << 1);
      p = (p * p) % mod;
    }
    return ret;
  }
  long long comb(int a, int b) {
    return (fac[a] * inv[b] % Mod) * inv[a - b] % Mod;
  }
  long long get(int x) { return fac[x]; }
  long long getInv(int x) { return inv[x]; }

 private:
  vector<long long> fac, inv;
};

class Solver {
 public:
  int n;
  Solver(LL n) : n(n){};

  void solve() {
    Modint<> ans(0);
    Factorial<> fac(n);
    vector<Modint<>> count(n);
    for (int i = (n + 1) / 2; i < n; ++i) {
      // i台以下でのマシンで全てのマスを塗る順列の数
      // = 各要素が{1,2}で長さ(i-1)の数列で，総和が(n-2)となるものの数 *
      // i!(i台の起動順) * (n-i)!(残りの起動順)
      // = (i-1)C(n-i-1)*i!*(n-i)!
      count[i] = Modint<>(fac.comb(i - 1, n - i - 1)) * fac.get(i) *
                 fac.get(n - 1 - i);
      ans += (count[i] - count[i - 1]) * i;
    }
    cout << ans << endl;
  }
};
}  // namespace Problem

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // std::cout << fixed << setprecsion(12);
  long long n = 0;
  std::cin >> n;

  Problem::Solver sol(n);
  sol.solve();
  return 0;
}
