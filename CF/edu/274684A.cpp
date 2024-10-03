#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 100'000;
  i32 st[N << 1], n, q, t;
  cin >> n;
  for (i32 i = n; i < n << 1; ++i) { cin >> st[i]; if ((i - n) & 1) st[i] = -st[i]; }
  for (i32 i = n - 1; ~i; --i) st[i] = st[i << 1] + st[i << 1 | 1];
  cin >> q;
  while (q--) {
    cin >> t;
    if (t) {
      i32 l0, l, r, res{};
      cin >> l0 >> r;
      --l0;
      for (l = l0 + n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += st[l++];
        if (r & 1) res += st[--r];
      }
      cout << (l0 & 1 ? -res : res) << '\n';
    } else {
      i32 idx, v;
      cin >> idx >> v;
      --idx;
      if (idx & 1) v = -v;
      for (st[idx += n] = v; idx > 1; idx >>= 1)
        st[idx >> 1] = st[idx] + st[idx ^ 1];
    }
  }
}

