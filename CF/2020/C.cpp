#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, a, b, c, d;
  cin >> TC;
  while (TC--) {
    cin >> b >> c >> d;
    a = b ^ d;
    if ((a | b) - (a & c) == d) cout << a << '\n';
    else cout << -1 << '\n';
  }
}
