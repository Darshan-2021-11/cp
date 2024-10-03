#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 150'000;
  int TC = 1, n, m, a[N][3];
  int64_t ans;
  char c;
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) a[i][0] = a[i][1] = a[i][2] = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> c;
        if (c == '?') ++a[j][2];
        else ++a[j][c ^ '0'];
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i][1] < a[i][0]) swap(a[i][0], a[i][1]);
      if (a[i][2] <= a[i][1] - a[i][0]) a[i][0] += a[i][2];
      else {
        a[i][2] -= a[i][1] - a[i][0], a[i][0] = a[i][1];
        a[i][1] += a[i][2] >> 1;
        a[i][0] += (a[i][2] >> 1) + (a[i][2] & 1);
      }
      ans += static_cast<int64_t>(a[i][0]) * a[i][1];
    }
    cout << ans << '\n';
  }
}
