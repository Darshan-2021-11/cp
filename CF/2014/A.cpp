#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n, k, t, have, ans;
  cin >> TC;
  while (TC--) {
    ans = have = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      if (t >= k) have += t;
      else if (!t && have) --have, ++ans;
    }
    cout << ans << '\n';
  }
}
