#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i64 m, tmp;
static i32 n, a[N], l, r, x, mx;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m;
  for (i32 i = 0; i < n; ++i) cin >> a[i];
  r = mx = *max_element(a, a + n), l = 0;
  while (l < r) {
    x = (l + r + 1) >> 1;
    tmp = 0;
    for (i32 i = 0; i < n; ++i) tmp += min(x, a[i]);
    if (tmp > m) r = x - 1;
    else l = x;
  }
  if (l == mx) cout << "infinite";
  else cout << l;
}
