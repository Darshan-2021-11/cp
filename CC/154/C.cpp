#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int64_t ans;
  int TC = 1, n, prev, a[N];
  array<int, 2> rng[N - 1];
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    prev = a[0] - 1;
    for (int i = 0; i < n - 1; ++i, prev = a[i] - 1)
      rng[i][0] = a[i + 1] - prev,
      rng[i][1] = a[i + 1] + prev;
    sort(rng, rng + n - 1);
    int l = 0, r = -1;
    for (int i = 0; i < n - 1; ++i)
      if (r < rng[i][0]) ans += r - l + 1, l = rng[i][0], r = rng[i][1];
      else r = max(r, rng[i][1]);
    ans += r - l + 1;
    cout << ans << '\n';
  }
}
