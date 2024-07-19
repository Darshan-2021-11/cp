#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;        using u32 = unsigned int;       using f32 = float;
using i64 = long long;  using u64 = unsigned long long; using f64 = double;
using i128 = __int128;  using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 20;
static i32 dp[1 << N], a[N], n, x, i, j, mask, submask, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> x;
  for (i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; ++i) {
    mask = 1 << i;
    for (j = 0; j < mask; ++j) {
      submask = j | mask;
      dp[submask] = dp[j] + a[i];
      if (dp[submask] > x) dp[submask] = 0;
    }
  }
  mask = (1 << n) - 1;
  while (mask) {
    submask = 0;
    for (j = mask; j; j = (j - 1) & mask) {
      if (dp[j] > dp[submask])
        submask = j;
      else if (dp[j] == dp[submask]) {
        if (__builtin_popcount(j) < __builtin_popcount(submask))
          submask = j;
        else submask = min(submask, j);
      }
    }
    ++ans, mask ^= submask;
  }
  cout << ans;
}
