#include <bits/stdc++.h>
using namespace std;

template <int SIZE>
struct suffix_array {
  using i32 = int;
  using i64 = long long int;
  i32 p[SIZE], c[SIZE], lcp[SIZE], _n; string data;
  suffix_array() noexcept : _n(0) { static_assert(SIZE >= (1 << 8)); }
  explicit suffix_array(const char *source, i32 size) noexcept : _n(size) { copy(source, source + size, data); make(); }
  /**
   * @brief Custom input function for `data` of suffix array
   */
  void input() noexcept { cin >> data; _n = data.size(); make(); }
  /**
   * @brief Creation of suffix array and LCP of given `data` array
   */
  void make() noexcept { i32 cn[SIZE], pn[SIZE]; array<i32, 2> pre, cur;
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
      if (cn[p[0]] != cn[p[1]]) break;
    }
  }
  /**
   * @brief Binary Search for upper_bound<1> or the lower_bound<0> for the given string in suffix-array
   * @param other pointer to the starting of string to search for
   * @param other_size size of the given string to search upto
   */
  template <bool ub> i32 bs(const char *other, i32 other_size) const noexcept { i32 hi = _n, lo = 1, x; next: while (lo < hi) { x = (lo + hi) >> 1; for (i32 i = 0; i < other_size; ++i) { if (data[p[x] + i] == other[i]) continue; if (data[p[x] + i] < other[i]) lo = x + 1; else hi = x; goto next; } if constexpr (ub) lo = x + 1; else hi = x; } return lo; }
  /**
   * @brief Count the number of occurances of the given string in suffix array
   * @param other pointer to the starting of string to search for
   * @param other_size size of the given string to search upto
   */
  i32 count(const char *other, i32 other_size) const noexcept { return bs<1>(other, other_size) - bs<0>(other, other_size); }
  /**
   * @brief Size of suffix array including null pointer at the end
   */
  i64 size() const { return _n; }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  auto start = std::chrono::high_resolution_clock::now();
  const int N = 1'000'000;
  suffix_array<N> sa;
  sa.input();
  for (int i = sa.p[0]; i < sa._n; ++i) putchar(sa.data[i]);
  for (int i = 0; i < sa.p[0]; ++i) putchar(sa.data[i]);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  fprintf(stderr, "\n%lf", duration.count());
}
