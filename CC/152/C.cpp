#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'001;
  int TC = 1, n, q, a[N][3], l, r, k, cnt;
  bool no;
  cin >> TC;
  while (TC--) {
    cin >> n >> q;
    fill_n(a[0], 3, 0);
    for (int i = 1, x; i <= n; ++i) {
      cin >> x;
      for (int j = 0; j < 3; ++j) a[i][j] = a[i - 1][j];
      ++a[i][x - 1];
    }
    while (q--) {
      cin >> l >> r;
      cnt = r - l + 1;
      if (cnt & 1) cout << "NO\n";
      else {
        k = no = false;
        for (int i = 0; i < 3; ++i) no |= a[r][i] - a[l - 1][i] > (cnt >> 1);
        for (int i = 0; i < 3; ++i) k += (a[r][i] - a[l - 1][i]) == (cnt >> 1);
        cout << (no || !k ? "NO\n" : "YES\n");
      }
    }
  }
}
