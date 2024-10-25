#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 201;
  int TC = 1, n, a[N], idx;
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (int i = 0; i <= n; ++i) cin >> a[i];
    sort(a, a + n);
    idx = n;
    for (int i = 0; i < n; ++i) if (a[i] <= (a[n] << 1) && a[i] > a[n]) swap(a[i], a[n]);
    cout << accumulate(a, a + n, 0) << '\n';
  }
}
