#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;        using u32 = unsigned int;       using f32 = float;
using i64 = long long;  using u64 = unsigned long long; using f64 = double;
using i128 = __int128;  using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 T, n, a[N], ans[3], mx[2], k[2];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    fill(ans, ans + 3, 0);
    fill(mx, mx + 2, 0);
    fill(k, k + 2, 0);
    cin >> n >> a[1];
    mx[1] = a[1];
    if (mx[1] == 1) ++ans[0];
    for (i32 i = 2; i <= n; ++i) {
      cin >> a[i];
      if (i & 1) {
        k[1] = max(0, k[1] +
            (max(mx[0], a[i]) == i - 1 ? 1 : (mx[1] == i - 1 ? -1 : 0)));
        ans[1] = max(ans[1], k[1]);
      } else {
        k[0] = max(0, k[0] +
            (max(mx[0], a[i]) == i - 1 ? 1 : (mx[1] == i - 1 ? -1 : 0)));
        ans[2] = max(ans[2], k[0]);
      }
      mx[1] = max(a[i], mx[0] = mx[1]);
      if (mx[1] == i) ++ans[0];
    }
    cout << ans[0] + max(ans[1], ans[2]) << '\n';
  }
}
