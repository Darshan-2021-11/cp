#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 30;
  i32 TC = 1, a[N], b[N], bn, n, q;
  cin >> TC;
  while (TC--) {
    cin >> n >> q;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    for (i32 i = 0, l, r; i < q; ++i) {
      bn = 0;
      cin >> l >> r;
      for (i32 i = l; i <= r; ++i) b[bn++] = a[i];
    }
  }
}

