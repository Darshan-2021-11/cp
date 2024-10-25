#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n, mn, mx;
  cin >> TC;
  while (TC--) {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    while (a.size() > 2) {
      mn = 0, mx = 0;
      for (int i = 1; i < 3; ++i) {
        if (a[mn] >= a[i]) mn = i;
        if (a[mx] <= a[i]) mx = i;
      }
      for (int i = 0; i < 3; ++i) {
        if (i == mn || i == mx) continue;
        a.erase(a.begin() + i);
      }
    }
    if (a[0] <= a[1]) {
      cout << n - 2 << '\n';
      for (int i = 0; i < n - 2; ++i) cout << 1 << ' ' << 3 << '\n';
    } else cout << -1 << '\n';
  }
}
