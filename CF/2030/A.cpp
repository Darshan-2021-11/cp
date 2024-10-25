#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n, mx, mn, ans;
  cin >> TC;
  while (TC--) {
    ans = 0, mx = INT_MIN, mn = INT_MAX;
    cin >> n;
    for (int i = 0, t; i < n; ++i) cin >> t, mx = max(mx, t), mn = min(mn, t);
    cout << (mx - mn) * (n - 1) << '\n';
  }
}
