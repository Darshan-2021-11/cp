#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, n;
  cin >> TC;
  while (TC--) {
    cin >> n;
    if (n < 4 && (n & 1)) {
      cout << -1 << '\n';
      continue;
    }
    if (n & 1) {
      for (int i = 0; i < n - 5; ++i) cout << '3';
      cout << "36366";
    } else {
      for (int i = 0; i < (n >> 1) - 1; ++i) cout << "33";
      cout << "66";
    }
    cout << '\n';
  }
}
