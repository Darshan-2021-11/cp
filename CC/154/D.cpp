#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, n, last;
  int64_t ans;
  bitset<N> a;
  cin >> TC;
  while (TC--) {
    last = -1, ans = 0;
    cin >> n;
    for (int i = 0, t; i < n; ++i) cin >> t, a[i] = t;
    for (int i = 0; i < n; ++i) {
      if (a[i]) {
        ++ans;
        if (i - 1 > -1 && a[i - 1]) last = i;
        else if (i - 2 > -1 && a[i - 2]) last = i - 1;
      }
      if (last != -1) ans += last;
    }
    cout << ans << '\n';
  }
}
