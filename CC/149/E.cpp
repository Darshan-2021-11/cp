#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  i32 TC = 1, n, x, t, mn, k, ans;
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n >> x >> k;
    map<i32, i32> m;
    for (i32 i = 0; i < n; ++i) cin >> t, ++m[t];
    t = INT_MAX;
    for (auto i = m.rbegin(); i != m.rend(); ++i) {
      if (i->second != 1 && i->first < x * k) {
        t = i->first;
        break;
      }
    }
    mn = (t / k) + (t % k != 0);
    for (auto i = m.rbegin(); i != m.rend(); ++i) {
      if (i->first >= x) continue;
      if (i->first >= mn) --i->second, ++ans;
      else break;
      x = i->first;
    }
    x *= k;
    for (auto i = m.rbegin(); i != m.rend(); ++i) {
      if (i->first >= x) continue;
      x = i->first;
      if (i->second) ++ans;
    }
    cout << ans << '\n';
  }
}

