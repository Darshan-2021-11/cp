#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'002;
static i32 TC, n, idx, a[N], d[N];
static i64 b[N], c[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 1; i <= n; ++i) cin >> a[i], c[i] = d[i] = 0;
    for (i32 i = 1; i <= n; ++i) cin >> b[i], b[i] += b[i - 1];
    for (i32 i = 1; i <= n; ++i) {
      idx = lower_bound(b + 1, b + n + 1, a[i] + b[i - 1]) - b;
      c[idx] += a[i] - (b[idx - 1] - b[i - 1]);
      d[i] += 1, d[idx] -= 1;
    }
    for (i32 i = 1; i <= n; ++i) {
      d[i] += d[i - 1];
      c[i] += (i64)d[i] * (b[i] - b[i - 1]);
    }
    for (i32 i = 1; i <= n; ++i) cout << c[i] << ' ';
    cout << '\n';
  }
}
