#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, a[N], n;
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    cout << min({ a[n - 3] - a[0], a[n - 1] - a[2], a[n - 2] - a[1] }) << '\n';
  }
}
