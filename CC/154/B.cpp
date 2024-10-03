#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, n, k, a[N];
  cin >> TC;
  while (TC--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool sm = true;
    for (int i = 0; i < n; ++i) sm &= a[i] == a[0];
    if (sm) {
      cout << (a[0] != k) << '\n';
      continue;
    }
    int nsm = 0;
    n = unique(a, a + n) - a;
    for (int i = 0; i < n; ++i) nsm += k != a[i];
    if (nsm == 1) cout << 1 << '\n';
    else {
      int mc = 0;
      for (int i = 0; i < n; ++i) mc += !(a[i] % k);
      if (mc == n) cout << 1 << '\n';
      else cout << 2 << '\n';
    }
  }
}
