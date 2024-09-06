#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, a[N], n, k, mn, mx, mxmod;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    mx = 0;
    cin >> n >> k;
    for (i32 i = 0; i < n; ++i) cin >> a[i], mx = max(mx, a[i]), a[i] = a[i] % (k << 1);
    sort(a, a + n);
    mn = INT_MAX, mxmod = a[n - 1];
    for (i32 i = 0; i < n; ++i) {
      if (mxmod - a[i] < k) {
        mn = min(mn, mx + ((mxmod + k) - (mx % k)) % k);
      }
      mxmod = a[i] + (k << 1);
    }
    if (mn == INT_MAX) {
      cout << -1 << '\n';
      continue;
    }
    cout << mn << '\n';
  }
}
