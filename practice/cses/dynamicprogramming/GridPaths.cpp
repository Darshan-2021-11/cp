#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;
 
u32 n, dp[(u32)1e3][(u32)1e3];
char path[(u32)1e3][(u32)1e3];
const u32 MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (u32 i = 0; i < n; ++i)
    for (u32 j = 0; j < n; ++j)
      cin >> path[i][j];
  dp[0][0] = path[0][0] == '.';
  for (u32 i = 1; i < n; ++i)
    dp[0][i] = (path[0][i] == '.') && dp[0][i - 1],
    dp[i][0] = path[i][0] == '.' && dp[i - 1][0];
  for (u32 i = 1; i < n; ++i) {
    for (u32 j = 1; j < n; ++j) {
      if (path[i][j] != '*') {
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        if (dp[i][j] >= MOD) dp[i][j] -= MOD;
      }
    }
  }
  cout << dp[n - 1][n - 1] << '\n';
}
