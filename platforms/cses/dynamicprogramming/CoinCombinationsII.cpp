#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;
 
u32 n, x, t, a[100], dp[(int)1e6 + 1];
const u32 MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> x;
  for (u32 i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dp[0] = 1;
  for (u32 j = 0; j < n; ++j) {
    t = a[j];
    for (u32 i = t; i <= x; ++i) {
      dp[i] += dp[i - t];
      if (dp[i] >= MOD) dp[i] -= MOD;
    }
  }

  cout << dp[x] << '\n';
}
