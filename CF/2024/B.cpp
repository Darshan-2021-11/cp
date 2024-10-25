#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int64_t TC = 1, a[N], n, k, ans, t, prev;
  cin >> TC;
  while (TC--) {
    cin >> n >> k;
    ans = prev = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
      if ((t = (a[i] - prev) * (n - i)) >= k) {
        ans += k;
        break;
      }
      else k -= t, ans += t + 1, prev = a[i];
    }
    cout << ans << '\n';
  }
}
