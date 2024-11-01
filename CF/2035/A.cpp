#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, n, m, r, c;
  cin >> TC;
  while (TC--) {
    cin >> n >> m >> r >> c;
    cout << ((m << 1) - 1) * (n - r) + (m - c) << '\n';
  }
}
