#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, n, k, t, mn;
  cin >> TC;
  for (int _ = 1; _ <= TC; ++_) {
    cin >> n >> k;
    mn = LLONG_MAX;
    for (int i = 0; i < n; ++i) cin >> t, mn = min(mn, t);
    if (n < 3) t = mn;
    else t = mn * (((n - 1) << 1) + 1);
    cout << "Case #" << _ << ": " << (t > k ? "NO\n" : "YES\n");
  }
}
