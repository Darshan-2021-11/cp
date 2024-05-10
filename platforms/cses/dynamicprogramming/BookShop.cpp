#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;
 
u32 n, x, si, pv, nv, h[1000], dp[(int)1e5 + 1];
const u32 MOD = 1e9 + 7;
int main() {
  scanf("%u %u", &n, &x);
  for (u32 i = 0; i < n; ++i)
    scanf("%u", h + i);

  for (u32 i = 0; i < n; ++i) {
    const u32 hi = h[i];
    scanf("%u", &si);
    for (u32 j = x; j <= x; --j)
      if (j >= hi)
        dp[j] = max(dp[j], dp[j - hi] + si), cout << dp[j] << ' ';
      else cout << dp[j] << ' ';
    cout << '\n';
  }
  cout << dp[x] << '\n';
}
