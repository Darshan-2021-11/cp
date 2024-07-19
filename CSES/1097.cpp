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

static i32 n, i, j;
static bool chance;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  vector<i64> a(n), t(n - 1), dp;
  for (i = 0; i < n; ++i) cin >> a[i];
  dp = a;
  for (i = 1; i < n; ++i) {
    for (j = 0; j + i < n; ++i) {
      t[j] = max(a[j + i] - dp[j], a[j] - dp[j + 1]);
    }
    dp = t;
  }
  cout << ((dp[0] + accumulate(a.begin(), a.end(), i64{})) >> 1);
}

