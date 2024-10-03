#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t n, mx1 = LLONG_MIN, mx2 = LLONG_MIN, t;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> t, mx1 = max(mx1, t);
  for (int i = 0; i < n; ++i) cin >> t, mx2 = max(mx2, t);
  cout << mx1 + mx2 << '\n';
}
