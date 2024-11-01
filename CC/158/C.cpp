#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int64_t res;
  int TC = 1, n, a[N], b[N], l[2], idx[2], taken;
  cin >> TC;
  while (TC--) {
    res = taken = 0;
    fill_n(l, 2, INT_MAX);
    l[1] = INT_MIN;
    fill_n(idx, 2, INT_MAX);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    if (n == 1) {
      cout << b[0] << '\n';
      continue;
    }
    for (int i = 0; i < n; ++i) if (b[i] <= a[i]) {
      ++taken, res += b[i];
      if (l[0] > a[i] - b[i]) idx[0] = i, l[0] = a[i] - b[i];
    }
    if ((n - taken) & 1) {
      for (int i = 0; i < n; ++i) if(a[i] < b[i]) {
        res += a[i];
        if (l[1] < b[i] - a[i]) idx[1] = i, l[1] = b[i] - a[i];
      }
      if (idx[0] != INT_MAX) cout << min(res - a[idx[1]] + b[idx[1]], res - b[idx[0]] + a[idx[0]]) << '\n';
      else cout << res + l[1] << '\n';
      continue;
    }
    else for (int i = 0; i < n; ++i) if(a[i] < b[i]) res += a[i];
    cout << res << '\n';
  }
}
