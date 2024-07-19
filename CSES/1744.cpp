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

static u32 a, b, i, j, k, dp[501][501];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> a >> b;
  dp[1][1] = 1;
  if (b > a) swap(a, b);
  for (i = 1; i <= b; ++i)
    for (j = 1; j <= a; ++j)
      dp[i][j] = -1;
  for (i = 1; i <= a; ++i) dp[1][i] = i;
  for (i = 1; i <= b; ++i) dp[i][1] = i;
  for (i = 2; i <= b; ++i) {
    for (j = 2; j <= a; ++j) {
      if (dp[i][j] != -1) continue;
      if (j % i) {
        for (k = 1; k <= (i + 1) >> 1; ++k) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
        for (k = 1; k <= (j + 1) >> 1; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
      } else {
        dp[i][j] = j / i;
        if (j <= b) dp[j][i] = dp[i][j];
      }
    }
  }
  cout << dp[b][a] - 1;
}
