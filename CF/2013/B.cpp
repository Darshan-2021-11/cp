#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n, p, c;
  int64_t sum;
  cin >> TC;
  while (TC--) {
    cin >> n;
    sum = 0;
    for (int i = 0, t; i < n - 2; ++i) cin >> t, sum += t;
    cin >> p >> c;
    cout << sum + c - p << '\n';
  }
}
