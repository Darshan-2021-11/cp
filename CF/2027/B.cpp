#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 2000;
  int TC = 1, n, a[N], ans;
  cin >> TC;
  while (TC--) {
    ans = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0, t; i < n; ++i) {
      t = i;
      for (int j = i; j < n; ++j) t += a[i] < a[j];
      ans = min(t, ans);
    }
    cout << ans << '\n';
  }
}
