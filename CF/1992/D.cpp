#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 T, n, m, k, dp[N];
static char a[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    for (i32 i = 0; i < n; ++i) cin >> a[i], dp[i] = 0;
    dp[n] = 0;
    for (i32 i{}, t = m - 1; i < n; ++i) {
      if (a[i] == 'L') t = m, dp[i + 1] = dp[i];
      else if (a[i] == 'C') {
        dp[i + 1] = dp[i];
        if (!t) {
          dp[n] = k + 1;
          break;
        }
      } else {
        if (!t) dp[i + 1] = dp[i] + 1;
        else dp[i + 1] = dp[i];
      }
      t = max(t - 1, 0);
    }
    cout << (dp[n] > k ? "NO\n": "YES\n");
  }
}

