#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int TC = 1, n, m, q, a, b[N];
  cin >> TC;
  while (TC--) {
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(b, b + m);
    while (q--) {
      cin >> a;
      int idx = lower_bound(b, b + m, a) - b;
      if (idx == m) {
        cout << n - b[m - 1] << '\n';
      } else if (idx == 0) {
        cout << (a == b[0] ? 0 : b[0] - 1) << '\n';
      } else {
        if (a == b[idx]) cout << 0 << '\n';
        else cout << ((b[idx] - b[idx - 1]) >> 1) << '\n';
      }
    }
  }
}
