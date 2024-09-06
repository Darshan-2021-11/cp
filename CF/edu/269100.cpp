#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 100'002;
static array<array<i32, 2>, N> t;
static i32 c[N], p[N], pc[N], idx[N], n, k;
static char a[N];

void radix_sort(array<array<i32, 2>, N> &x) {
  fill_n(idx, n, 0);
  for (i32 i = 0; i < n; ++i) ++idx[x[i][1] + 1];
  partial_sum(idx, idx + n, idx);
  for (i32 i = 0; i < n; ++i) pc[idx[x[i][1]]++] = i;
  fill_n(idx, n, 0);
  for (i32 i = 0; i < n; ++i) ++idx[x[pc[i]][0] + 1];
  partial_sum(idx, idx + n, idx);
  for (i32 i = 0; i < n; ++i) p[idx[x[pc[i]][0]]++] = pc[i];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  n = k = 0;
  while ((a[n] = getchar()) != '\n') ++n;
  a[n++] = '`';
  {
    fill_n(idx, 27, 0);
    for (i32 i = 0; i < n; ++i) idx[a[i] - '`' + 1] = true;
    partial_sum(idx, idx + 27, idx);
  }
  for (i32 i = 0; i < n; ++i) c[i] = idx[a[i] - '`'];
  while ((1 << k) < n) {
    for (i32 i = 0, x; i < n; ++i) {
      x = i + (1 << k);
      if (x >= n) x -= n;
      t[i] = { c[i], c[x] };
    }
    radix_sort(t);
    c[p[0]] = 0;
    for (i32 i = 1; i < n; ++i) {
      if (t[p[i - 1]][0] == t[p[i]][0] && t[p[i - 1]][1] == t[p[i]][1])
        c[p[i]] = c[p[i - 1]];
      else
        c[p[i]] = c[p[i - 1]] + 1;
    }
    ++k;
  }
  for (i32 i = 0; i < n; ++i) printf("%d ", p[i]);
}
