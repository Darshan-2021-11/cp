#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 TC, n, x, sum;
static i32 const N = 100'000;
static i32 a[N], ans, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    sum = ans = 0;
    cin >> n >> x;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (i32 i = n - 1; ~i; i--) {
      if (a[i] >= x) sum += a[i] - x, ++ans;
      else if (sum >= (t = x - a[i])) sum -= t, ++ans;
      else break;
    }
    cout << ans << '\n';
  }
}
