#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF = 334ll << 53;
constexpr int INF = 15 << 26;
constexpr LL MOD = 1E9 + 7;

// newest
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


// stable
template <long long Mod = MOD>
struct Modint {
 public:
  // long long Mod = MOD;
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
  Modint operator/(Modint a) { return a.mpow(Mod - 2) * *this; }
};
template <long long M>
ostream &operator<<(ostream &os, const Modint<M> m) {
  return os << m.v;
}

// old
long long modpow(long long a, long long n) {
  if (n == 0) return 1;
  long long re = modpow((a * a) % MOD, n / 2) % MOD;
  if (n % 2 == 1) re = (re * a) % MOD;
  return re;
}
template <long long Mod = MOD>
struct Modint {
 public:
  // long long Mod = MOD;
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
    v = (v * modpow(a.v, Mod - 2)) % Mod;
    return *this;
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
    long long t = (v)*modpow(a.v, Mod - 2);
    return Modint(t);
  }
};
ostream &operator<<(ostream &os, const Modint<> m) { return os << m.v; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  return 0;
}
