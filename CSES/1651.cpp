#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'000;
  i64 st[N << 1]{};
  i32 n, q;
  cin >> n >> q;
  for (i32 i = n; i < n << 1; ++i) cin >> st[i];
  while (q--) {
    i32 t; cin >> t;
    if (t == 1) {
      i32 l, r, v; cin >> l >> r >> v; --l;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) st[l++] += v;
        if (r & 1) st[--r] += v;
      }
    } else {
      i32 k; cin >> k; --k;
      i64 ans = 0;
      for (k += n; k; k >>= 1) ans += st[k];
      cout << ans << '\n';
    }
  }
}

