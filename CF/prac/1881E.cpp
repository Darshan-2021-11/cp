#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, a[N], dp[N], lst[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    lst[n] = n, dp[n] = 0;
    for (i32 i = n - 1, u, v; ~i; --i) {
      v = dp[i + 1] + 1;
      if (a[i] + i < n) {
        u = dp[i + a[i] + 1];
        if (u < v) {
          lst[i] = i, dp[i] = u;
          continue;
        }
      }
      lst[i] = lst[i + 1], dp[i] = v;
    }
    cout << dp[0] << '\n';
  }
}
