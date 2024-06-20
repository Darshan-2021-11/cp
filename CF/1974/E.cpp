#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, m, c[50], h[50], sh, ans;
static u64 x, dph[(u32)5e4 + 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    ans = 0;
    cin >> m >> x >> c[0] >> h[0];
    sh = h[0];
    for (u32 i = 1; i < m; ++i) {
      cin >> c[i] >> h[i];
      sh += h[i];
    }
    for (u32 i = 0; i <= sh; ++i) dph[i] = UINT64_MAX;
    dph[0] = 0;
    if (!c[0]) dph[h[0]] = 0;
    for (u32 i = 1; i < m; ++i) {
      const u32 hi = h[i], ci = c[i];
      for (u32 j = sh; j >= hi; --j) {
        if (dph[j - hi] == UINT64_MAX) continue;
        if (ci + dph[j - hi] <= x * i) dph[j] = min(ci + dph[j - hi], dph[j]);
      }
    }
    for (u32 i = 1; i <= sh; ++i)
      if (dph[i] != UINT64_MAX) ans = i;
    cout << ans << '\n';
  }
}

