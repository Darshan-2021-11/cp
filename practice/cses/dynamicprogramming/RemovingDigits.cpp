#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 n, t, tr, i, dp[(u32)1e6 + 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  memset(dp + 1, -1, n * sizeof(u32));
  for (i = 1; i <= n; ++i) {
    t = i;
    while (t) {
      tr = t % 10, t /= 10;
      if (tr) dp[i] = min(1 + dp[i - tr], dp[i]);
    }
    //cout << i << ' ' << dp[i] << '\n';
  }
  cout << dp[n] << '\n';
}

