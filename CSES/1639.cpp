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

static i32 i, j, n, m, pre, tmp, ans, dp[5001];
static char a[5001], b[5001];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  while ((a[n] = getchar_unlocked()) != '\n') ++n;
  while ((b[m] = getchar_unlocked()) != '\n') ++m;
  for (j = 1; j <= m; ++j) dp[j] = j;
  for (i = 1; i <= n; ++i) {
    for (j = 1, tmp = dp[0]++; j <= m; ++j, pre = tmp) {
      tmp = dp[j];
      if (a[i - 1] == b[j - 1]) dp[j] = pre;
      else dp[j] = min({ dp[j - 1], dp[j], pre }) + 1;
    }
  }
  printf("%d", dp[m]);
}
