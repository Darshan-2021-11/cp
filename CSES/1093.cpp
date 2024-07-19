#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
static const int MOD = 1e9 + 7, MODINV2 = 500000004;
static int n, t, i, j;

int modinv(int a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * modinv(MOD % a) % MOD;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  t = (n * (n + 1)) >> 1;
  if (t & 1) {
    cout << 0;
    return 0;
  }
  t >>= 1;
  vector<int> dp(t + 1);
  dp[0] = 1;
  for (i = 1; i <= n; ++i) {
    for (j = t; j >= i; --j) {
      dp[j] += dp[j - i];
      if (dp[j] >= MOD) dp[j] -= MOD;
    }
  }
  //cout << ((long long)modinv(2) * dp[t] % MOD);
  cout << ((long long)MODINV2 * dp[t] % MOD);
}
