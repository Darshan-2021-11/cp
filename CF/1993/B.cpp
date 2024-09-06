#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i64 TC, a[N], n, c1, mx, mxe, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    c1 = 0, ans = 0;
    mx = mxe = 0;
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i], c1 += (a[i] & 1);
    if (c1 == 0 || c1 == n) {
      cout << 0 << '\n';
      continue;
    }
    sort(a, a + n, greater<i32>());
    for (i32 i = 0; i < n; ++i) if (a[i] & 1) { mx = a[i]; break; }
    for (i32 i = 0; i < n; ++i) if (!(a[i] & 1)) { mxe = a[i]; break; }
    for (i32 i = n - 1; ~i; --i) {
      if (a[i] & 1) continue;
      if (a[i] > mx) ++ans, mx += mxe;
      mx = a[i] + mx, ++ans;
    }
    cout << ans << '\n';
  }
}

