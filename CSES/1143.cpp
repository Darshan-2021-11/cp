#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'000;
  i32 st[N << 1], n, m;
  cin >> n >> m;
  for (i32 i = n; i < n << 1; ++i) cin >> st[i];
  for (i32 i = n - 1; i; --i) st[i] = max(st[i << 1], st[i << 1 | 1]);
  while (m--) {
    i32 sz;
    cin >> sz;
    if (sz > st[1]) cout << 0 << ' ';
    else {
      i32 idx = 1, l = 0, r = n;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          if (st[l] >= sz) { idx = l; break; }
          ++l;
        }
        if (r & 1) {
          --r;
          if (st[r] >= sz) idx = r;
        }
      }
      while (idx < n) {
        idx <<= 1;
        idx += st[idx] < sz;
      }
      cout << idx - n + 1 << ' ';
      for (st[idx] -= sz; idx > 1; idx >>= 1) st[idx >> 1] = max(st[idx], st[idx ^ 1]);
    }
  }
}
