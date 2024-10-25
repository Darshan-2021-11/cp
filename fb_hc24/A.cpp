#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(10), cout.setf(ios::fixed);
  const int N = 1'000'001;
  using ld = long double;
  int TC = 1, n, less, more;
  array<ld, 2> a[N];
  ld t, l, r;
  cin >> TC;
  for (int _ = 1; _ <= TC; ++_) {
    l = 0.0000000001, r = 1e8;
    less = more = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1];
    while (r - l >= 1e-9) {
      less = 0, more = 0;
      ld x = l + (r - l) / 2;
      for (int i = 1; i <= n; ++i) {
        t = i / x;
        if (t >= a[i][0] && t <= a[i][1]) continue;
        else if (t < a[i][0]) ++less;
        else ++more;
      }
      if (less) r = x;
      else if (more) l = x;
      else r = x;
    }
    bool found = true;
    for (int i = 1; i <= n; ++i) {
      t = i / r;
      found &= t >= a[i][0];
      found &= t <= a[i][1];
    }
    if (!found) cout << "Case #" << _ << ": " << -1 << '\n';
    else cout << "Case #" << _ << ": " << r << '\n';
  }
}
