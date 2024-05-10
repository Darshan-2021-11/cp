#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 n, m, x, dp[(u32)1e5][102], ans;
const u32 MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m >> x;
  if (x == 0)
    for (u32 i = 1; i <= m; ++i) dp[0][i] = 1;
  else
    dp[0][x] = 1;
  for (u32 i = 1; i < n; ++i) {
    cin >> x;
    if (x == 0) {
      for (u32 j = 1; j <= m; ++j) {
        dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
        while (dp[i][j] >= MOD) dp[i][j] -= MOD;
      }
    } else {
      u32 j = x;
      dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
      while (dp[i][j] >= MOD) dp[i][j] -= MOD;
    }
  }
  for (u32 i = 1; i <= m; ++i) {
    ans += dp[n - 1][i];
    if (ans >= MOD) ans -= MOD;
  }
  cout << ans << '\n';
}
