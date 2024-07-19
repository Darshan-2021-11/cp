#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 200'000;
static i64 T, i, n, m, a[N], b[N], cost, mincost;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    cost = 0, mincost = static_cast<i64>(1) << 60;
    cin >> n >> m;
    for (i = 0; i < n; ++i) cin >> a[i];
    for (i = 0; i < n; ++i) cin >> b[i];
    for (i = m; i < n; ++i) {
      cost += min(a[i], b[i]);
    }
    for (i = m - 1; i >= 0; --i) {
      mincost = min(cost + a[i], mincost);
      cost += b[i];
    }
    cout << mincost << '\n';
  }
}

