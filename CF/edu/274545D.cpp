#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'000;
  i32 st[N << 1], a[N >> 1], n;
  cin >> n;
  n <<= 1;
  fill_n(st, n << 1, 0);
  fill_n(a, n >> 1, -1);
  auto merge = [](i32 x, i32 y) -> i32 {
    return x + y;
  };
  auto query = [&st, &merge, &n](i32 l, i32 r) -> i32 {
    i32 res{};
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = merge(res, st[l++]);
      if (r & 1) res = merge(res, st[--r]);
    }
    return res;
  };
  auto update = [&st, &merge, &n](i32 idx, i32 v) -> void {
    for (st[idx += n] = v; idx > 1; idx >>= 1) st[idx >> 1] = merge(st[idx], st[idx ^ 1]);
  };
  for (i32 i = 0, t; i < n; ++i) {
    cin >> t; --t;
    if (a[t] == -1) a[t] = i;
    else update(a[t], 1), a[t] = i - a[t] - ((query(0, i) - query(0, a[t])) << 1) + 1;
  }
  for (i32 i = 0; i < n >> 1; ++i) cout << a[i] << ' ';
}
