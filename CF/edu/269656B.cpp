#pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
template <i32 N>
struct suffix_array {
  i32 p[N + 1] {}, c[N + 1] {}, lcp[N + 1] {}, _n, bp; char data[N + 1];
  suffix_array() : _n(0) { while ((data[_n] = getchar()) != '\n') ++_n; data[_n++] = '\n', bp = _n; while ((data[_n] = getchar()) != '\n') ++_n; make(); }
  suffix_array(const char *source, i32 size) : _n(size) { assert(N >= (1 << 8)); copy(source, source + size, data); make(); }
  void make() { i32 cn[N + 1], pn[N + 1]; array<i32, 2> pre, cur; data[_n++] = '\0';
    {
      fill_n(lcp, (1 << 8), 0); for (i32 i = 0; i < _n; ++i) ++lcp[c[i] = data[i] - '\0']; for (i32 i = 0; i < (1 << 8); ++i) pn[i] = lcp[i] != 0;
      partial_sum(lcp, lcp + (1 << 8), lcp); for (i32 i = 0; i < _n; ++i) p[--lcp[c[i]]] = i;
      pn[0] = 0; partial_sum(pn, pn + (1 << 8), pn); for (i32 i = 0; i < _n; ++i) c[i] = pn[c[i]];
    }
    for (i32 k = 0; (1 << k) < _n; ++k, copy(cn, cn + _n, c)) {
      for (i32 i = 0; i < _n; ++i) { pn[i] = p[i] - (1 << k); if (pn[i] < 0) pn[i] += _n; }
      fill_n(lcp, _n, 0); for (i32 i = 0; i < _n; ++i) ++lcp[c[pn[i]]]; partial_sum(lcp, lcp + _n, lcp); for (i32 i = _n - 1; ~i; --i) p[--lcp[c[pn[i]]]] = pn[i];
      cn[p[0]] = 0; i32 x = p[0] + (1 << k); if (x >= _n) x -= _n; pre = { c[p[0]], c[x] };
      for (i32 i = 1; i < _n; ++i, pre = cur) {
        x = p[i] + (1 << k); if (x >= _n) x -= _n; cur = { c[p[i]], c[x] };
        if (cur == pre) cn[p[i]] = cn[p[i - 1]]; else cn[p[i]] = cn[p[i - 1]] + 1;
      }
    }
    for (i32 i = 0, k = 0, x = c[i], y = p[x - 1]; i < _n - 1; lcp[x - 1] = k, ++i, k = max(k - 1, 0), x = c[i], y = p[x - 1]) while (data[i + k] == data[y + k]) ++k;
    lcp[c[_n - 1] - 1] = 0;
  }
  template <bool ub>
    i32 bs(const char *other, i32 other_size) const { i32 hi = _n, lo = 1, x; next: while (lo < hi) { x = (lo + hi) >> 1; for (i32 i = 0; i < other_size; ++i) { if (data[p[x] + i] == other[i]) continue; if (data[p[x] + i] < other[i]) lo = x + 1; else hi = x; goto next; } if constexpr (ub) lo = x + 1; else hi = x; } return lo; }
  i32 count(const char *other, i32 other_size) const { return bs<1>(other, other_size) - bs<0>(other, other_size); }
  i32 size() const { return _n; }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  suffix_array<N> s;
  i32 mx = 0, idx;
  for (i32 i = 0; i < s.size() - 1; ++i)
    if (((s.p[i] < s.bp) ^ (s.p[i + 1] < s.bp)) && s.lcp[i] > mx) mx = s.lcp[i], idx = s.p[i];
  for (i32 i = 0; i < mx; ++i) putchar(s.data[idx + i]);
}
