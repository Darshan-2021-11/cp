#pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

const i32 N = 150'000;

template <i32 SIZE>
struct suffix_array {
  i32 p[SIZE + 1], c[SIZE + 1], lcp[SIZE + 1], _n; char data[SIZE + 1];
  suffix_array() noexcept : _n(0) {}
  suffix_array(const char *source, i32 size) noexcept : _n(size) { copy(source, source + size, data); make(); }
  void input(i32 n) noexcept { i32 t; for (_n = 0; _n < n; ++_n) cin >> t, data[_n] = t; make(); }
  void make() noexcept { i32 cn[SIZE + 1], pn[SIZE + 1]; array<i32, 2> pre, cur; data[_n++] = '\0';
    assert(SIZE >= (1 << 8));
    {
      fill_n(lcp, (1 << 8), 0); for (i32 i = 0; i < _n; ++i) ++lcp[c[i] = data[i] - '\0']; for (i32 i = 0; i < (1 << 8); ++i) pn[i] = lcp[i] != 0;
      partial_sum(lcp, lcp + (1 << 8), lcp); for (i32 i = 0; i < _n; ++i) p[--lcp[c[i]]] = i;
      pn[0] = 0; partial_sum(pn, pn + (1 << 8), pn); for (i32 i = 0; i < _n; ++i) c[i] = pn[c[i]];
    }
    for (i32 k = 0; (1 << k) < _n; ++k, copy(cn, cn + _n, c)) {
      for (i32 i = 0; i < _n; ++i) { pn[i] = p[i] - (1 << k); if (pn[i] < 0) pn[i] += _n; }
      fill_n(lcp, _n, 0); for (i32 i = 0; i < _n; ++i) ++lcp[c[i]]; partial_sum(lcp, lcp + _n, lcp); for (i32 i = _n - 1; ~i; --i) p[--lcp[c[pn[i]]]] = pn[i];
      cn[p[0]] = 0; i32 x = p[0] + (1 << k); if (x >= _n) x -= _n; pre = { c[p[0]], c[x] };
      for (i32 i = 1; i < _n; ++i, pre = cur) {
        x = p[i] + (1 << k); if (x >= _n) x -= _n; cur = { c[p[i]], c[x] };
        if (cur == pre) cn[p[i]] = cn[p[i - 1]]; else cn[p[i]] = cn[p[i - 1]] + 1;
      }
    }
    for (i32 i = 0, k = 0, x = c[i], y = p[x - 1]; i < _n - 1; lcp[x - 1] = k, ++i, k = max(k - 1, 0), x = c[i], y = p[x - 1]) while (data[i + k] == data[y + k]) ++k;
    lcp[_n - 1] = 0;
  }
  template <bool ub> i32 bs(const char *other, i32 other_size) const noexcept { i32 hi = _n, lo = 1, x; next: while (lo < hi) { x = (lo + hi) >> 1; for (i32 i = 0; i < other_size; ++i) { if (data[p[x] + i] == other[i]) continue; if (data[p[x] + i] < other[i]) lo = x + 1; else hi = x; goto next; } if constexpr (ub) lo = x + 1; else hi = x; } return lo; }
  i32 count(const char *other, i32 other_size) const noexcept { return bs<1>(other, other_size) - bs<0>(other, other_size); }
  i64 size() const { return _n; }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  i32 n, m;
  cin >> n >> m;
  suffix_array<N> s;
  s.input(n);
  stack<array<i32, 2>> stk; array<i32, 2> y; bool b = false;
  i64 ans = s.size() - 1, t;
  i32 k = ans, idx = 0;
  stk.push({ 0, 0 });
  for (i32 i = 1; i < s.size(); ++i, b = false) {
    while (stk.top()[0] > s.lcp[i]) {
      b = true;
      y = stk.top(); stk.pop();
      t = static_cast<i64>(i - y[1] + 1) * y[0];
      if (ans < t) ans = t, k = y[0], idx = s.p[y[1]];
    }
    if (stk.top()[0] != s.lcp[i]) stk.push({ s.lcp[i], (b ? y[1] : i) });
  }
  cout << ans << '\n';
  cout << k << '\n';
  for (i32 i = 0; i < k; ++i) cout << static_cast<i32>(s.data[idx + i]) << ' ';
}
