#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100;
  int TC = 1, n, mx[2];
  cin >> TC;
  while (TC--) {
    mx[0] = mx[1] = 0;
    cin >> n;
    for (int i = 0, t; i < n; ++i) {
      cin >> t;
      mx[i & 1] = max(mx[i & 1], t);
    }
    cout << max(mx[0] + (n & 1), mx[1]) + (n >> 1) << '\n';
  }
}
