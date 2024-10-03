#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'000;
  array<i32, 2> a[N];
  i32 TC = 1, n, ans;
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n;
    set<i32> s;
    for (i32 i = 0; i < n; ++i) cin >> a[i][0], s.insert(a[i][0]);
    for (i32 i = 0; i < n; ++i) cin >> a[i][1];
    sort(a, a + n, [](array<i32, 2> x, array<i32, 2> y) {
        return static_cast<i64>(x[0]) * y[1] < static_cast<i64>(x[1]) * y[0];
        });
    for (i32 i = 0, j, mx; i < n; i = j) {
      j = i;
      mx = a[i][0];
      while (j < n && static_cast<i64>(a[i][0]) * a[j][1] == static_cast<i64>(a[i][1]) * a[j][0]) {
        auto it = s.find(a[j++][0]);
        if (it == s.end()) continue;
        mx = max(mx, a[j - 1][0]);
        s.erase(it), ++ans;
      }
      while (s.size() && *s.begin() < mx) s.erase(s.begin());
    }
    cout << ans << '\n';
  }
}

