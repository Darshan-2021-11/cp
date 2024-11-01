#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, n, a[N], mn, x, mask, res;
  cin >> TC;
  while (TC--) {
    mn = INT_MAX;
    res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], mn = min(a[i], mn);
    x = 32 - __builtin_clz(mn);
    mask = (1 << x) - 1;
    for (int i = 0; i < n; ++i) mask &= a[i];
    if (mask == 0) {
      cout << 0 << '\n';
      continue;
    }
    for (int i = x - 1; ~i; --i) {
      if ((mask >> i) & 1) res += (1 << i);
    }
    cout << res << '\n';
  }
}
