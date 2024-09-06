#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 TC, n, x, a, b, c, t, ans, bpc, bmc, D;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n >> x;
    for (a = 1; a <= x - 2; ++a) {
      bpc = min(x - a, (n - 1 + a) / a);
      bmc = n - a * bpc;
      t = (bpc * bpc) + (bmc << 2);
      D = sqrtl(t);
      b = (bpc + D) >> 1;
      c = (bpc - D) >> 1;
      if (c > 0)
        ans += (b * c) << 1;
      else ans += (b + c - 1) << 1;
    }
    cout << ans << '\n';
  }
}

