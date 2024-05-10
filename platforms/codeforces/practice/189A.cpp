#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 n, steps[3], dp[4001];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);

  cin >> n >> steps[0] >> steps[1] >> steps[2];
  sort(steps, steps + 3);
  for (u32 j = 0; j < 3; ++j) {
    if (steps[j] > n) break;
    dp[n - steps[j]] = max(1 + dp[n], dp[n - steps[j]]);
  }
  for (u32 i = n - 1; i < n; --i) {
    if (!dp[i]) continue;
    for (u32 j = 0; j < 3; ++j) {
      if (steps[j] > i) break;
      dp[i - steps[j]] = max(1 + dp[i], dp[i - steps[j]]);
    }
  }
  cout << dp[0] << '\n';
}
