#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static u32 TC, n, t, dp[19], ans;
static unsigned char a[20];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    ans = UINT32_MAX;
    cin >> n;
    for (i32 i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] ^= '0';
    }
    dp[0] = 10 * a[0] + a[1];
    for (i32 j = 2, k = 1; j < n; ++j, ++k) {
      dp[k] = min(dp[k - 1] * a[j], dp[k - 1] + a[j]);
    }
    ans = min(ans, dp[n - 2]);
    for (i32 i = 1; i < n - 1; ++i) {
      dp[0] = a[0];
      for (i32 j = 1, k = 1; j < n; ++j, ++k) {
        if (j == i) {
          t = 10 * a[j] + a[j + 1];
          dp[k] = min(dp[k - 1] * t, dp[k - 1] + t);
          ++j;
        } else dp[k] = min(dp[k - 1] * a[j], dp[k - 1] + a[j]);
      }
      ans = min(ans, dp[n - 2]);
    }
    cout << ans << '\n';
  }
}
