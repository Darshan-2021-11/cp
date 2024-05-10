#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;
 
int n, x, a[100], dp[(int)1e6 + 1];
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dp[0] = 1;
  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i >= a[j]) {
        dp[i] += dp[i - a[j]];
        if (dp[i] >= MOD) dp[i] -= MOD;
      }
    }
  }
  cout << dp[x] << '\n';
}
