#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 400'001;
static i32 c[N], p[N], cn[N], pn[N], lcp[N], n, bn, q, k, x, i, lo, hi;
static array<i32, 2> pre, cur;
static char a[N], b[N], ch;

static void count_sort() {
  fill_n(lcp, n, 0);
  for (i = 0; i < n; ++i) ++lcp[c[pn[i]]];
  partial_sum(lcp, lcp + n, lcp);
  for (i = n - 1; ~i; --i) p[--lcp[c[pn[i]]]] = pn[i];
}

template <bool ub>
static i32 bs() {
  hi = n, lo = 1;
next:
  while (lo < hi) {
    x = (lo + hi) >> 1;
    for (i = 0; i < bn; ++i) {
      if (a[p[x] + i] == b[i]) continue;
      if (a[p[x] + i] < b[i]) lo = x + 1;
      else hi = x;
      goto next;
    }
    if constexpr (ub) lo = x + 1;
    else hi = x;
  }
  return lo;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  n = k = 0;
  while ((a[n] = getchar()) != '\n') ++n;
  a[n++] = '`';
  {
    fill_n(lcp, 27, 0);
    for (i = 0; i < n; ++i) ++lcp[c[i] = a[i] - '`'];
    for (i = 0; i < 27; ++i) pn[i] = lcp[i] != 0; pn[0] = 0;
    partial_sum(lcp, lcp + 27, lcp);
    partial_sum(pn, pn + 27, pn);
    for (i = 0; i < n; ++i) p[--lcp[c[i]]] = i;
    for (i = 0; i < n; ++i) c[i] = pn[c[i]];
  }
  for (k = 0; (1 << k) < n; ++k) {
    for (i = 0; i < n; ++i) {
      pn[i] = p[i] - (1 << k);
      if (pn[i] < 0) pn[i] += n;
    }
    count_sort();
    cn[p[0]] = 0;
    x = p[0] + (1 << k);
    if (x >= n) x -= n;
    pre = { c[p[0]], c[x] };
    for (i = 1; i < n; ++i) {
      x = p[i] + (1 << k);
      if (x >= n) x -= n;
      cur = { c[p[i]], c[x] };

      if (cur == pre)
        cn[p[i]] = cn[p[i - 1]];
      else
        cn[p[i]] = cn[p[i - 1]] + 1;
      pre = cur;
    }
    copy(cn, cn + n, c);
  }
  for (i = 0; i < n; ++i) printf("%d ", p[i]);
  putchar('\n');
  /*
  q = 0;
  while ((ch = getchar()) != '\n') q = q * 10 + (ch - '0');
  while (q--) {
    bn = 0;
    while ((b[bn] = getchar()) != '\n') ++bn;
    printf("%d\n", bs<1>() - bs<0>());
  }
  */
  for (i = 0, k = 0; i < n - 1; ++i) {
    x = c[i];
    q = p[x - 1];
    while (a[i + k] == a[q + k]) ++k;
    lcp[x - 1] = k;
    k = max(k - 1, 0);
  }
  lcp[c[i] - 1] = 0;
  for (i = 0; i < n - 1; ++i) printf("%d ", lcp[i]);
}
