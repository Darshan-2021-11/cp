#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static u32 TC, n, k, i, j, cnt0, mx;
static array<u32, 2> a[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cnt0 = 0;
    cin >> n >> k;
    for (i = 0; i < n; ++i) cin >> a[i][0];
    for (i = 0; i < n; ++i) cin >> a[i][1], cnt0 += a[i][1] == 0;
    sort(a, a + n);
    if (n == 2) {
      if (a[0][1] == 0) cout << a[0][0] + a[1][0] + (a[1][1] == 0 ? 0 : k) << '\n';
      else cout << a[0][0] + a[1][0] + k << '\n';
    }
    i = (n - 2) >> 1, j = i;
    mx = a[n - 1][0] + a[i][0];
    while (true) {
      if (a[i][1] == 0) {
        while (~j && a[j][1] == 0) --j;
        if (~j) break;
        mx = max(mx, a[n - 1][0] + a[i][0]);
        swap(a[i], a[j]);
      }
      a[i] += min()
    }
    cout << mx << '\n';
  }
}
