#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i64 TC, n, m, k, w, a[N];
static i64 req[N], ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n >> m >> k >> w;
    for (i32 i = 0; i < w; ++i) cin >> a[i];
    sort(a, a + w, greater<i32>());
    for (i64 i = 1, t = 0; i <= n; ++i) {
      for (i64 j = 1; j <= m; ++j, ++t) {
        req[t] = 
          ((min(m, j + k - 1) - max(1LL, j - k + 1) + 1) - (k - 1)) *
          ((min(n, i + k - 1) - max(1LL, i - k + 1) + 1) - (k - 1));
      }
    }
    sort(req, req + n * m, greater<i64>());
    for (i32 i = 0; i < w; ++i) {
      ans += req[i] * a[i];
    }
    cout << ans << '\n';
  }
}
