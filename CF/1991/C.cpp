#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, a[N], k, x, b[40];
static bool yes;

void perform() {
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    yes = false, k = 0;
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    for (k = 0; k < 40; ++k) {
      x = *max_element(a, a + n) + *min_element(a, a + n);
      if (!x) { yes = true; break; }
      if (x & 1) break;
      x >>= 1;
      b[k] = x;
      for (i32 i = 0; i < n; ++i) a[i] = abs(a[i] - x);
    }
ans:
    if (!yes) {
      cout << -1 << '\n';
      continue;
    }
    cout << k << '\n';
    for (i32 i = 0; i < k; ++i) cout << b[i] << ' ';
    cout << '\n';
  }
}
