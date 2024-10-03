#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 100'000;
  i32 st[N << 1], n, m;
  cin >> n >> m;
  for (i32 i = n; i < n << 1; ++i) cin >> st[i];
  for (i32 i = n - 1; i; --i) st[i] = max(st[i << 1], st[i << 1 | 1]);
  while (m--) {
    i32 t;
    cin >> t;
    if (t == 2) {
      i32 x, l, idx = -1, r = n << 1;
      cin >> x >> l;
      for (l += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          if (st[l] >= x) { idx = l; break; }
          ++l;
        }
        if (r & 1) {
          --r;
          if (st[r] >= x) idx = r;
        }
      }
      if (idx == -1) { cout << -1 << '\n'; continue; }
      while (idx < n) {
        idx <<= 1;
        idx += st[idx] < x;
      }
      cout << idx - n << '\n';
    } else {
      i32 idx, v;
      cin >> idx >> v;
      for (st[idx += n] = v; idx > 1; idx >>= 1) st[idx >> 1] = max(st[idx], st[idx ^ 1]);
    }
  }
}
