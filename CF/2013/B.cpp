#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, i, n, t;
  int64_t sum;
  cin >> TC;
  while (TC--) {
    for (cin >> n, sum = i = 0; i < n - 2; ++i) cin >> t, sum += t;
    cin >> t; sum -= t; cin >> t; sum += t;
    cout << sum << '\n';
  }
}
