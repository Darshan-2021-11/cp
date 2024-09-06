#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, a[N], h, l, x, lw, hg;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    n = unique(a, a + n) - a;
    if (n < 3) {
      cout << 0 << '\n';
      continue;
    }
    l = 0, h = 1e9 + 1;
    while (l < h) {
      x = (l + h) >> 1;
      lw = upper_bound(a, a + n, a[0] + (x << 1)) - a;
      hg = lower_bound(a, a + n, a[n - 1] - (x << 1)) - a;
      if (a[hg] >= a[n - 1] - (x << 1) && hg) --hg;
      if (lw >= hg || a[hg] - a[lw] <= (x << 1)) h = x;
      else l = x + 1;
    }
    cout << l << '\n';
  }
}

