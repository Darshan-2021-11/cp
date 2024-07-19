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

static i32 n, i, j, maxn, cnt, a[1000];
static bool dp[1'000'001];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  dp[0] = true;
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    for (j = maxn; ~j; --j) {
      dp[j + a[i]] |= dp[j];
    }
    maxn += a[i];
  }
  for (j = 1; j <= maxn; ++j)
    cnt += dp[j];
  cout << cnt << '\n';
  for (j = 1; j <= maxn; ++j) if (dp[j]) cout << j << ' ';
}

