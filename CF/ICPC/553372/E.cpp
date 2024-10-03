#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, n, k, a[500];
  bool yes;
  cin >> TC;
  while (TC--) {
    cin >> n >> k;
    yes = false;
    iota(a, a + n, 1);
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    do {
      bool yest = true;
      int odd = 0, even = 0, oddc, evenc;
      for (int i = 0; i < k; ++i) odd += a[i] & 1, even += !(a[i] & 1);
      oddc = odd, evenc = even;
      for (int i = k; i < n; ++i) {
        oddc += a[i] & 1, evenc += !(a[i] & 1);
        oddc -= a[i - k] & 1, evenc += !(a[i - k] & 1);
        yest &= oddc == odd, yest &= evenc == even;
      }
      if (yest) { yes = true; break; }
    } while (next_permutation(a, a + n));
    cout << (yes ? "YES\n" : "NO\n");
  }
}
