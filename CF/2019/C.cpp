#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n;
  int64_t t, k, sum, mx, ans;
  cin >> TC;
  while (TC--) {
    sum = ans = mx = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> t, sum += t, mx = max(mx, t);
    for (int i = n; i; --i) {
      t = (sum - 1 + i) / i;
      if (k >= max(t, mx) * i - sum) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
}
