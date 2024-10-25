#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int TC = 1, n, res, a[N];
  cin >> TC;
  while (TC--) {
    res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < (n >> 1); ++i) if (a[i] == a[i - 1] || a[n - 1 - i] == a[n - i]) swap(a[i], a[n - 1 - i]);
    for (int i = 1; i < n; ++i) res += a[i] == a[i - 1];
    cout << res << '\n';
  }
}
