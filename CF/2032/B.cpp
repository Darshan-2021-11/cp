#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n, k;
  cin >> TC;
  while (TC--) {
    cin >> n >> k;
    if (k == 1 || k == n) {
      if (n == 1) {
        cout << 1 << '\n';
        cout << 1 << '\n';
      } else cout << -1 << '\n';
      continue;
    }
    if (((k - 1) & 1) == ((n - k) & 1)) {
      cout << 3 << '\n';
      if ((k - 1) & 1) {
        cout << 1 << ' ';
        cout << k << ' ';
        cout << k + 1 << '\n';
      } else {
        cout << 1 << ' ';
        cout << k - 1 << ' ';
        cout << k + 2 << '\n';
      }
    } else cout << -1 << '\n';
  }
}
