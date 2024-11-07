#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int64_t st[N << 1], dp[N], res;
  int a[N], n, k, l, r;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i], --a[i], dp[i] = 1;
  while (k--) {
    fill_n(st, n << 1, 0);
    for (int i = n - 1; ~i; --i) {
      res = 0;
      for (l = a[i] + 1 + n, r = n << 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += st[l++];
        if (r & 1) res += st[--r];
      }
      for (l = a[i] + n, st[l] = dp[a[i]]; l >>= 1;) st[l] = st[l << 1] + st[l << 1 | 1];
      dp[a[i]] = res;
    }
  }
  cout << accumulate(dp, dp + n, int64_t{});
}
