#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, k, a[N];
static i64 ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n >> k;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    if (n & 1) ans += a[0];
    for (i32 i = n - 1; i > 0; i -= 2) {
      if (k >= a[i] - a[i - 1]) k -= a[i] - a[i - 1];
      else if (k) ans += a[i] - (a[i - 1] + k), k = 0;
      else ans += a[i] - a[i - 1];
    }
    cout << ans << '\n';
  }
}

