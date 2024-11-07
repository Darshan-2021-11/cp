#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int64_t TC = 1, n, x, t, a[N];
  cin >> TC;
  while (TC--) {
    bool win = true;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> t, a[i] -= t;
    sort(a, a + n, greater<int64_t>());
    for (int i = 0; i <= n >> 1; ++i) {
      if (a[i] > 0) continue;
      else if (a[i] <= 0 and x < - a[i] + 1) { win = false; break; }
      else x += a[i] - 1;
    }
    cout << (win ? "YES\n" : "NO\n");
  }
}
