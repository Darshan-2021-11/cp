#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 200'001;
static i64 TC, n, x, a[N], dp[N];
static i32 i, res, l, r, mid;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> x;
    for (i32 i = 1; i <= n; ++i) {
      cin >> a[i];
      a[i] += a[i - 1];
    }
    for (i32 i = 1; i <= n; ++i) {
      r = n, l = i - 1;
      res = i - 1;
      while (l <= r) {
        mid = (r + l) >> 1;
        if (a[mid] - a[i - 1] > x) r = mid - 1;
        else res = max(res, mid), l = mid + 1;
      }
      dp[i] = res - i + 1;
    }
    for (i32 i = n; i; --i) {
      if (i + dp[i] + 1 > n) continue;
      dp[i] += dp[i + dp[i] + 1];
    }
    cout << accumulate(dp + 1, dp + n + 1, i64{}) << '\n';
  }
}

