#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static constexpr u32 MAX = 1e7;
static u32 T = 1, l, r, factor[MAX + 1];
static bool found;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  for (u32 i = 2, j; (j = i * i) <= MAX; ++i) {
    for (; j <= MAX; j += i) {
      if (factor[j]) continue;
      factor[j] = i;
    }
  }
  cin >> T;

  while (T--) {
    found = false;
    cin >> l >> r;
    for (u32 i = l; i <= r; ++i) {
      if (factor[i] == 0) continue;
      found = true;
      cout << factor[i] << ' ' << i - factor[i] << '\n';
      break;
    }
    if (!found) cout << -1 << '\n';
  }
}

