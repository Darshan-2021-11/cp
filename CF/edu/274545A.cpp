#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 100'000;
  i32 n, st[N << 1];
  cin >> n;
  fill_n(st, n << 1, 0);
  for (i32 i = 0, t, l, r, inv; i < n; ++i) {
    cin >> t;
    for (l = t + n - 1, ++st[l]; l > 1; l >>= 1) st[l >> 1] = st[l] + st[l ^ 1];
    for (inv = 0, l = t + n, r = n << 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) inv += st[l++];
      if (r & 1) inv += st[--r];
    }
    cout << inv << ' ';
  }
}

