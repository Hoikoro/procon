#include <bits/stdc++.h>
using namespace std;
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

struct Problem {
  LL a, b, lb, ub;
  set<pair<LL, LL>> rangeOr, canMake;
  void insert_(set<pair<LL, LL>> &st, pair<LL, LL> t) {
    auto it = st.lower_bound(make_pair(t.first, 0ll));
    if (it != st.begin()) {
      auto it2 = it;
      it2--;
      if (it2->second >= t.first) {
        pair<LL, LL> tmp = *it2;
        tmp.second = max(tmp.second, t.second);
        st.erase(it2);
        it = st.insert(it, tmp);
      } else {
        it = st.insert(it, t);
      }
    } else {
      it = st.insert(it, t);
    }
    auto nxt = it;
    nxt++;
    if (nxt != st.end() && it->second >= nxt->first) {
      pair<LL, LL> tmp = *it;
      tmp.second = max(tmp.second, nxt->second);
      st.erase(it);
      st.erase(nxt);
      st.insert(tmp);
    }
  }
  void restrictRange(int digit) {
    if (digit >= 60) return;
    set<pair<LL, LL>> res;
    LL interval = (1ll << (digit + 1));
    for (auto p : canMake) {
      LL a = p.first, b = p.second;
      for (LL j = (a + interval) / interval * interval; j < b + interval;
           j += interval) {
        insert_(res, {a % interval,
                      (min(b, j) % interval == 0 ? interval
                                                 : min(b, j) % interval)});
        a = j;
      }
    }
    swap(canMake, res);
  }
  void mask(int digit) {
    set<pair<LL, LL>> res;
    LL interval = (1ll << (digit));
    for (auto p : canMake) {
      LL a = p.first, b = p.second;
      for (LL j = (a + interval) / interval * interval; j < b + interval;
           j += interval) {
        if (((a >> (digit)) & 1) == 0) {
          insert_(res, {a % interval,
                        (min(b, j) % interval == 0 ? interval
                                                   : min(b, j) % interval)});
        }
        a = j;
      }
    }
    swap(canMake, res);
  }
  void solve() {
    cin >> a >> b;
    rangeOr.emplace(a, b + 1);
    canMake.emplace(a, b + 1);
    ub = 1;
    while (ub <= b) ub <<= 1;
    for (int i = 60; i >= 0; --i) {
      LL bUpper = (b >> i) << i;
      restrictRange(i);
      if ((1ll << i) > b or ((b >> i) & 1) == 1) continue;
      for (auto p : canMake) {
        insert_(rangeOr, {bUpper + p.first, bUpper + p.second});
      }
      mask(i);
    }
    LL ans = 0;
    for (auto p : rangeOr) {
      ans += p.second - p.first;
    }
    cout << ans << endl;
  }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  Problem p;
  p.solve();
  return 0;
}
