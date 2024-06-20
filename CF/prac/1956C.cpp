#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n, ansn;
static u64 ans[501];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  ansn = 0;

  while (TC--) {
    cin >> n;
    if (n == 1) {
      cout << 1 << ' ' << 1 << '\n';
      cout << 1 << ' ' << 1 << ' ' << 1 << '\n';
      continue;
    }
    while (n > ansn) {
      ++ansn;
      ans[ansn] = ans[ansn - 1] + ((u64)ansn * ((ansn << 1) - 1));
    }
    cout << ans[n] << ' ' << (n << 1) << '\n';
    for (u32 i = 1; i <= n; ++i) {
      cout << 1 << ' ';
      cout << n + 1 - i << ' ';
      for (u32 j = 1; j <= n; ++j) cout << j << ' ';
      cout << '\n';
      cout << 2 << ' ';
      cout << n + 1 - i << ' ';
      for (u32 j = 1; j <= n; ++j) cout << j << ' ';
      cout << '\n';
    }
  }
}

