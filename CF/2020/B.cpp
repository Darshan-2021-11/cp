#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  uint64_t TC = 1, k, l, r, x;
  cin >> TC;
  /*
  for (int i = 1; i < 100; ++i) {
    bitset<102> b;
    for (int j = 2; j <= i; ++j) {
      for (int t = j; t <= i; t += j) b.flip(t);
    }
    cout << i << ':' << ' ' << b.count() << '\n';
  }
  */

  while (TC--) {
    cin >> k;
    l = 1, r = 1e18;
    r += 1e9 + 1;
    while (l < r) {
      x = (l + r) >> 1;
      if (x < k + (uint64_t)sqrtl(x)) l = x + 1;
      else r = x;
    }
    cout << l << '\n';
  }
}
