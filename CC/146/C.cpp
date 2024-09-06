#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 100'001;
static i32 TC, n, a[N], ans;
static i64 sum, pf;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = sum = pf = 0;
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    if (sum == 0) {
      cout << (n << 1) << '\n';
      continue;
    }
    for (i32 i = 1; i < n - 1; ++i) {
      sum -= a[i - 1], pf += a[i - 1];
      if (a[i] != 0) continue;
      i64 df = abs(sum - pf);
      if (!df) ans += 2;
      if (df == 1) ans += 1;
    }
    cout << ans << '\n';
  }
}

