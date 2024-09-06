#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'001;
  i64 TC = 1, n, mp[N] {}, idx, t, ans;
  cin >> TC;
  while (TC--) {
    cin >> n;
    ans = 0, idx = n;
    mp[0] = n;
    for (i32 i = 0, x, y; i < n; ++i) {
      cin >> x >> y;
      --mp[0];
      if (mp[y] + 1 > mp[idx]) {
        idx = y;
      }
      if (y != idx) ans += mp[y];
      ++mp[y];
      t = mp[idx] + mp[0];
      cout << ans + ((t * (t - 1)) >> 1) << ' ';
    }
    cout << '\n';
    for (i32 i = 0, t; i <= n; ++i) mp[i] = 0;

  }
}
