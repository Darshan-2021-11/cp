#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n, x, y;
  cin >> TC;
  while (TC--) {
    cin >> n >> x >> y;
    cout << max((n + x - 1) / x, (n + y - 1) / y) << '\n';
  }
}
