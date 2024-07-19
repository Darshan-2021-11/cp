#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC, x[3], i, j, l, r, mc, tmc;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    mc = INT_MAX;
    for (i = 0; i < 3; ++i) cin >> x[i];
    sort(x, x + 3);
    l = x[0], r = x[2];
    if (l == r) {
      cout << 0 << '\n';
      continue;
    }
    for (j = l, tmc = 0; j <= r; ++j, tmc = 0) {
      for (i = 0; i < 3; ++i) tmc += abs(x[i] - j);
      mc = min(mc, tmc);
    }
    cout << mc << '\n';
  }
}

