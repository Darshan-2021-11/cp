#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T, n, x, dp[(u32)1e6][2];
const u32 MOD = 1e9 + 7;

struct Matrix {
  u32 dp[2][2];
};
Matrix operator * (const Matrix &a, const Matrix &b){
  Matrix ret;
  u32 i, j, k;
  for(i = 0; i < 2; i++)
    for(j = 0; j < 2; j++) {
      ret.dp[i][j] = 0;
      for(k = 0; k < 2; k++) {
        ret.dp[i][j] += ((u64)a.dp[i][k]) * b.dp[k][j] % MOD;
        if(ret.dp[i][j] >= MOD)
          ret.dp[i][j] -= MOD;
      }
    };
  return ret;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  /**
   * O(n) implementation
   *
   *  // dp[m][0] : stores the one where bottom does not have horizontal separation
   *  // dp[m][1] : stores the one where bottom does have horizontal separation
   *  dp[0][0] = 1, dp[0][1] = 1, n = 1;
   *  while (T--) {
   *    cin >> x;
   *    while (n < x) {
   *      dp[n][0] = (((u64)dp[n - 1][0] << 1) + dp[n - 1][1]) % MOD;
   *      dp[n][1] = (((u64)dp[n - 1][1] << 2) + dp[n - 1][0]) % MOD;
   *      ++n;
   *    }
   *    cout << (dp[x - 1][0] + dp[x - 1][1]) % MOD << '\n';
   *  }
   */

  /**
   * O(log(n)) implementation
   */
  while (T--) {
    Matrix base = {{ // base is transformation matrix
      { 2, 1 },
      { 1, 4 }
    }}, ans = {{ // ans is identity matrix
      { 1, 0 },
      { 0, 1 }
    }};
    cin >> x;
    --x;
    while (x) {
      if (x & 1) ans = ans * base;
      base = base * base;
      x >>= 1;
    }
    cout << (ans.dp[0][0] + ans.dp[0][1] + ans.dp[1][0] + ans.dp[1][1]) % MOD << '\n';
  }
}

