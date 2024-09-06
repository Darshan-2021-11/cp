#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 100'001;
static i64 TC, n, x[N], y[N], s[2], t[2], dx, dy, dx1, dy1, d2, d2i;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }
    cin >> s[0] >> s[1];
    cin >> t[0] >> t[1];
    dx = s[0] - t[0];
    dy = s[1] - t[1];
    d2 = dx * dx;
    d2 += dy * dy;
    i32 yes = 1;
    for (i32 i = 0; i < n; ++i) {
      dx1 = x[i] - t[0];
      dy1 = y[i] - t[1];
      d2i = (i128)dx1 * dx1;
      d2i -= d2;
      d2i += (i128)dy1 * dy1;
      if (d2i > 0) continue;
      yes = 0;
      break;
    }
    cout << (yes ? "YES" : "NO") << '\n';
  }
}

