#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'000;
  i32 st[N << 1], n, q;
  cin >> n >> q;
  for (i32 i = n; i < n << 1; ++i) cin >> st[i];
  for (i32 i = n - 1; i; --i) st[i] = st[i << 1] ^ st[i << 1 | 1];
  while (q--) {
    i32 l, r, res = 0;
    cin >> l >> r;
    --l;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res ^= st[l++];
      if (r & 1) res ^= st[--r];
    }
    cout << res << '\n';
  }
}
