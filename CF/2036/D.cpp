#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1'000;
  int TC = 1, cnt, n, m, tn;
  char a[N][N], t[(((N << 1) - 2) << 1) + 3];
  cin >> TC;
  while (TC--) {
    cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    for (int i = 0; i < min(n >> 1, m >> 1); ++i) {
      tn = 0;
      for (int j = i; j < m - 1 - i; ++j) t[tn++] = a[i][j];
      for (int j = i; j < n - 1 - i; ++j) t[tn++] = a[j][m - 1 - i];
      for (int j = m - 1 - i; j > i; --j) t[tn++] = a[n - 1 - i][j];
      for (int j = n - 1 - i; j > i; --j) t[tn++] = a[j][i];
      for (int j = i; tn < ((n - (i << 1) + m - (i << 1) - 2) << 1) + 3 && j < m - 1 - i; ++j) t[tn++] = a[i][j];
      if (tn < ((n - (i << 1) + m - (i << 1) - 2) << 1) + 3) t[tn++] = a[i][m - 1 - i];
      if (tn < ((n - (i << 1) + m - (i << 1) - 2) << 1) + 3) t[tn++] = a[i + 1][m - 1 - i];
      for (int j = 0; j < tn - 3; ++j) {
        if (t[j] == '1' && t[j + 1] == '5' && t[j + 2] == '4' && t[j + 3] == '3') ++cnt;
      }
    }
    cout << cnt << '\n';
  }
}
