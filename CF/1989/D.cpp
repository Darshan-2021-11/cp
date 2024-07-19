#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 1'000'001;
static i32 n, m, t, c[N], dp[N];
static array<i32, 2> fm[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m;
  i32 mxa{};
  for (i32 i{}; i < n; ++i) cin >> fm[i][0], mxa = max(mxa, fm[i][0]);
  for (i32 i{}; i < n; ++i) cin >> fm[i][1];
  for (i32 i{}; i < m; ++i) cin >> c[i];
  sort(fm, fm + n);

  i32 p{}, cost = fm[0][0] - fm[0][1];
  for (i32 ai{}, i{fm[ai][0]}; i <= mxa; ++i) {
    while (ai + 1 < n && fm[ai + 1][0] == i) {
      ++ai;
      if (cost > (t = fm[ai][0] - fm[ai][1])) cost = t, p = ai;
    }
    dp[i] = dp[i - cost] + 1;
  }
  i64 ans{};
  for (i32 i{}; i < m; ++i) {
    if (c[i] > fm[p][0]) {
      t = (c[i] - fm[p][0] + cost - 1) / cost;
      ans += (c[i] - fm[p][0] + cost - 1) / cost + dp[c[i] - t * cost];
    } else ans += dp[c[i]];
  }
  cout << (ans << 1);
}
