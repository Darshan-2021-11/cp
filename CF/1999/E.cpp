#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'002;
static i32 TC, dp[N], l, r;
static i64 ans, ddp[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  for (i32 i = 1; i < N; ++i) dp[i] = 1 + dp[i / 3];
  for (i32 i = 1; i < N; ++i) ddp[i] = ddp[i - 1] + dp[i];
  cin >> TC;
  while (TC--) {
    cin >> l >> r;
    cout << dp[l] + ddp[r] - ddp[l - 1] << '\n';
  }
}

