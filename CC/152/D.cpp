#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 400'001, MOD = 998'244'353;
  int64_t ans, n, cnt[2];
  int TC = 1, fm[N], p, c, cnt0, pairs;
  fm[0] = 1;
  for (int i = 1; i <= (N >> 1); ++i) fm[i] = (static_cast<int64_t>(fm[i - 1]) * i) % MOD;
  cin >> TC;
  while (TC--) {
    ans = 1;
    cnt[0] = cnt[1] = cnt0 = pairs = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> p >> c;
      if (p == 0) pairs += c == 0, ++cnt0;
      cnt0 += c == 0;
      ++cnt[p > n];
      ++cnt[c > n];
    }
    cnt[1] = n - cnt[1];
    cnt[0] = cnt0 - cnt[1];
    while (pairs--) (ans <<= 1) %= MOD;
    (ans *= fm[cnt[0]]) %= MOD;
    (ans *= fm[cnt[1]]) %= MOD;
    cout << ans << '\n';
  }
}
