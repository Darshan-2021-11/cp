#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1 << 11;
  int TC = 1, n, a[N], b[N];
  cin >> TC;
  while (TC--) {
    cin >> n;
    vector<pair<int, int>> s;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int k = 1, i, j, pos; k <= n; ++k) {
      for (i = 0; i < n; ++i) if (b[i] == k) break;
      for (j = 0; j < n; ++j) if (a[j] == k) break;
      if (i > j) {
        cout << 'z' << '\n';
        for (int l = 0; l < n; ++l) cout << a[l] << ' ';
        cout << '\n';
        for (int l = 0; l < n; ++l) cout << b[l] << ' ';
        cout << '\n';
        goto fail;
      }
      if (i == j) continue;
      pos = j;
      for (--j; j >= i; --j) {
        if (a[j] > a[pos]) {
          swap(a[j], a[pos]);
          s.emplace_back(j, pos);
          pos = j;
        }
      }
      if (a[i] != b[i]) {
        cout << 'y' << '\n';
        for (int l = 0; l < n; ++l) cout << a[l] << ' ';
        cout << '\n';
        for (int l = 0; l < n; ++l) cout << b[l] << ' ';
        cout << '\n';
        goto fail;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        cout << 'x' << '\n';
        for (int l = 0; l < n; ++l) cout << a[l] << ' ';
        cout << '\n';
        for (int l = 0; l < n; ++l) cout << b[l] << ' ';
        cout << '\n';
        goto fail;
      }
    }
    cout << s.size() << '\n';
    for (const auto &[i, j]: s) cout << i + 1 << ' ' << j + 1 << '\n';
    continue;
fail:
    cout << -1 << '\n';
  }
}
