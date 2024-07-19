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

static i64 TC, i, j, n, bn, k, a[2000], b[1'999'000], ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    ans = LLONG_MAX, bn = 0;
    cin >> n >> k;
    for (i = 0; i < n; ++i) cin >> a[i], ans = min(ans, a[i]);
    if (k > 2) {
      cout << 0 << '\n';
      continue;
    }
    sort(a, a + n);
    for (i = 1; i < n; ++i) ans = min(ans, a[i] - a[i - 1]);
    if (k == 1) {
      cout << ans << '\n';
      continue;
    }
    for (i = 0; i < n; ++i) {
      for (j = i + 1; j < n; ++j) {
        b[bn++] = a[j] - a[i];
      }
    }
    sort(b, b + bn);
    j = 0;
    for (i = 0; i < bn; ++i) {
      if (b[i] > a[j]) break;
      ans = min(ans, a[j] - b[i]);
    }
    for (++j; i < bn; ++i) {
      while (b[i] > a[j]) ++j;
      ans = min({ ans, abs(a[j - 1] - b[i]), abs(a[j] - b[i]) });
    }
    cout << ans << '\n';
  }
}
