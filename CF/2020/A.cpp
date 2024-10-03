#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, n, a[33], an, ans;
  cin >> TC;
  while (TC--) {
    an = 0, ans = 0;
    cin >> n >> a[0];
    if (a[0] == 1) {
      cout << n << '\n';
      continue;
    }
    while (n > a[an]) ++an, a[an] = a[an - 1] * a[0];
    while (an >= 0) {
      if (n >= a[an]) ans += n / a[an], n %= a[an];
      --an;
    }
    ans += n;
    cout << ans << '\n';
  }
}
