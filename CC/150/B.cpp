#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 101;
  i32 TC = 1, n, a[N], mp[N] {}, idx, ans;
  cin >> TC;
  while (TC--) {
    cin >> n;
    ans = 0, idx = n;
    for (i32 i = 0, t; i < n; ++i) cin >> a[i], ++mp[a[i]];
    for (i32 i = 1, t; i <= n; ++i) {
      if (mp[i] > mp[idx]) idx = i;
    }
    mp[idx] += mp[0];
    for (i32 i = 1, t; i <= n; ++i) ans += (mp[i] * (mp[i] - 1)) >> 1;
    cout << ans << '\n';
    for (i32 i = 0, t; i <= n; ++i) mp[i] = 0;

  }
}

