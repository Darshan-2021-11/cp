#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'000;
static i32 n, ans, a[N], pf[N], sf[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (i32 i = 0; i < n; ++i) cin >> a[i], ++pf[i], ++sf[i];
  if (n == 2) {
    cout << 1 + (a[0] < a[1]);
    return 0;
  }
  for (i32 i = 1; i < n; ++i) {
    if (a[i - 1] < a[i])
      pf[i] = pf[i - 1] + 1;
    ans = max(ans, pf[i]);
  }
  for (i32 i = n - 2; ~i; --i) {
    if (a[i] < a[i + 1])
      sf[i] = sf[i + 1] + 1;
  }
  for (i32 i = 2; i < n; ++i) {
    if (a[i] > a[i - 2]) ans = max(ans, pf[i - 2] + sf[i]);
  }
  cout << ans;
}
