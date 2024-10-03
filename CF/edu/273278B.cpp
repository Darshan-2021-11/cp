#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 100'000;
  i32 st[N << 1], t[18], n, q, tx, x, l, r, idx, tn;
  cin >> n >> q;
  for (i32 i = n; i < n << 1; ++i) cin >> st[i];
  for (i32 i = n - 1; i; --i) st[i] = st[i << 1] + st[i << 1 | 1];
  while (q--) {
    cin >> tx;
    if (tx == 2) {
      cin >> x;
      ++x;
      for (tn = 0, idx = -1, l = n, r = n << 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          if (st[l] >= x) { idx = l; break; }
          x -= st[l++];
        }
        if (r & 1) t[tn++] = --r;
      }
      if (idx == -1) {
        while (tn) {
          if (st[t[--tn]] >= x) { idx = t[tn]; break; }
          x -= st[t[tn]];
        }
      }
      // never reached
      if (idx == -1) {
        cout << -1 << ' ';
        continue;
      }
      while (idx < n) {
        idx <<= 1;
        if (st[idx] < x) x -= st[idx], idx += 1;
      }
      cout << idx - n << ' ';
    } else {
      cin >> idx;
      for (st[idx += n] ^= 1; idx > 1; idx >>= 1) st[idx >> 1] = st[idx] + st[idx ^ 1];
    }
  }
}
