#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 400'001;
static i32 c[N], p[N], cn[N], pn[N], cnt[N], n, k, x, i;
static array<i32, 2> pre, cur;
static char a[N];

void count_sort() {
  fill_n(cnt, n, 0);
  for (i = 0; i < n; ++i) ++cnt[c[pn[i]]];
  partial_sum(cnt, cnt + n, cnt);
  for (i = n - 1; ~i; --i) p[--cnt[c[pn[i]]]] = pn[i];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  n = k = 0;
  while ((a[n] = getchar()) != '\n') ++n;
  a[n++] = '`';
  {
    fill_n(cnt, 27, 0);
    for (i = 0; i < n; ++i) ++cnt[c[i] = a[i] - '`'];
    for (i = 0; i < 27; ++i) pn[i] = cnt[i] != 0; pn[0] = 0;

    partial_sum(cnt, cnt + 27, cnt);
    partial_sum(pn, pn + 27, pn);
    for (i = 0; i < n; ++i) p[--cnt[c[i]]] = i;
    for (i = 0; i < n; ++i) c[i] = pn[c[i]];
  }
  for (k = 0; (1 << k) < n; ++k) {
    for (i = 0; i < n; ++i) {
      x = p[i] - (1 << k);
      if (x < 0) x += n;
      pn[i] = x;
    }
    count_sort();
    cn[p[0]] = 0;
    x = p[0] + (1 << k);
    if (x >= n) x -= n;
    pre = { c[p[0]], c[x] };
    for (i = 1; i < n; ++i) {
      // We are not doing the 2nd element of `cur` as
      // c[p[x]], where x = (i + (1 << k)) % n, but as
      // c[x], where x = (p[i] + (1 << k)) % n, because
      // we need the class of this index before sorting
      // to update the class, not the new index at that place.
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
}
