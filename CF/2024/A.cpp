#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, a, b;
  cin >> TC;
  while (TC--) {
    cin >> a >> b;
    cout << (a >= b ? a : (a << 1) <= b ? 0 : (a << 1) - b) << '\n';
  }
}
