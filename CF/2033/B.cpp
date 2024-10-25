#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 500;
  int TC = 1, a[N][N], n, t, res;
  cin >> TC;
  while (TC--) {
    res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
    for (int i = 0, u; i < n; ++i) {
      t = INT_MAX, u = i;
      for (int j = 0; u < n; ++j) t = min(t, a[u++][j]);
      if (t >= 0) continue;
      res += -t;
    }
    for (int j = 1, u; j < n; ++j) {
      t = INT_MAX, u = j;
      for (int i = 0; u < n; ++i) t = min(t, a[i][u++]);
      if (t >= 0) continue;
      res += -t;
    }
    cout << res << '\n';
  }
}
