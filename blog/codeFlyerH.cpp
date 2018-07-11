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
class SegmentSieve {
  long long lower, upper, range;
  vector<long long> primes;  // prime number in[2,sqrt(b)]
  vector<vector<pair<long long, int>>> prime_factor;
  vector<char> is_prime_seg;
  void sieve() {
    vector<char> isprime(range + 1, 1);
    vector<long long> table(upper - lower);
    iota(table.begin(), table.end(), lower);
    isprime[0] = isprime[1] = 0;
    for (long long i = 2; i <= range; i++) {
      if (isprime[i]) {
        primes.push_back(i);
        for (long long j = i * i; j <= range; j += i) isprime[j] = 0;
        for (long long j = lower - lower % i; j < upper; j += i) {
          if (j >= lower) {
            is_prime_seg[j - lower] = false;
            int ord = 0;
            while (table[j - lower] % i == 0) {
              table[j - lower] /= i;
              ord++;
            }
            prime_factor[j - lower].emplace_back(i, ord);
          }
        }
      }
    }
    for (int i = 0; i < (int)prime_factor.size(); ++i) {
      if (table[i] != 1) prime_factor[i].emplace_back(table[i], 1);
    }
  }

 public:
  SegmentSieve(long long a, long long b)
      : lower(a),
        upper(b),
        prime_factor(b - a),
        is_prime_seg(b - a, 1) {  //[a,b)
    range = max(b - a + 1, (long long)sqrt(b) + 1);
    sieve();
  };
  bool is_prime(long long x) {
    // assert(lower <= x && x < upper);
    return is_prime_seg[x - lower];
  }
  vector<pair<long long, long long>> divisor_euler(long long x) {
    // assert(lower <= x && x < upper);
    vector<pair<long long, long long>> ret = {{1ll, 1}};
    for (const auto p : prime_factor[x - lower]) {
      int sz = (int)ret.size();
      for (int i = 0; i < sz; ++i) {
        long long divisor = ret[i].first;
        long long euler_ = ret[i].second;
        for (int d = 1; d <= p.second; ++d) {
          divisor *= p.first;
          euler_ *= (d == 1 ? (p.first - 1) : p.first);
          ret.emplace_back(divisor, euler_);
        }
      }
    }
    return ret;
  }
};

class Solver {
 public:
  LL w, h;
  vector<LL> x, y;
  Solver() : x(3), y(3){};

  void solve() {
    for (int i = 0; i < 3; ++i) {
      cin >> x[i] >> y[i];
    }
    cin >> w >> h;
    Modint<> area(0), on_edge(0);
    area = Modint<>(h).mpow(3) * Modint<>(w).mpow(3) / 2 *
           (Modint<>(x[1] - x[0]) * Modint<>(y[2] - y[0]) -
            Modint<>(x[2] - x[0]) * Modint<>(y[1] - y[0]));
    on_edge += calc(x[0], y[0], x[1], y[1]);
    on_edge += calc(x[0], y[0], x[2], y[2]);
    on_edge += calc(x[1], y[1], x[2], y[2]);

    cout << area + Modint<>(h).mpow(3) * Modint<>(w).mpow(3) - on_edge / 2
         << endl;
  }
  Modint<> calc_sum(LL k, LL center, LL width) {
    Modint<> ret(0);
    //等差数列の和の部分

    long long r = center - center % k;
    long long l = (center - width + k - 1) / k * k;
    ret += Modint<>((r - l) / k + 1) *
           Modint<>(h - abs(center - r) + h - abs(center - l)) / 2;

    long long r2 = center + width - (center + width) % k;
    long long l2 = (center + 1 + k - 1) / k * k;
    ret += Modint<>((r2 - l2) / k + 1) *
           Modint<>(h - abs(center - r2) + h - abs(center - l2)) / 2;

    return ret;
  }
  Modint<> calc(LL a, LL b, LL c, LL d) {
    if (a > c) swap(a, c);
    if (b > d) swap(b, d);
    SegmentSieve segs(c - a - w + 1, c - a + w);
    Modint<> ret(0);
    /*for (LL i = c - a - w + 1; i < c - a + w; ++i) {
      Modint<> tmp(0);
      for (LL j = d - b - h + 1; j < d - b + h; ++j) {
        tmp += Modint<>(__gcd(i, j)) * (h - abs(j - d + b));
      }
      ret += Modint<>(h * w) * tmp * (w - abs(i - c + a));
    }*/
    for (LL i = c - a - w + 1; i < c - a + w; ++i) {
      Modint<> tmp(0);
      for (auto p : segs.divisor_euler(i)) {
        auto div = p.first;
        auto euler = p.second;
        tmp += calc_sum(div, d - b, h) * euler;
      }
      ret += Modint<>(h * w) * tmp * (w - abs(i - c + a));
    }
    return ret;
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
