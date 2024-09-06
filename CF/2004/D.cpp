#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, q, l, r, a[N], p[N][6], s[N][6], t[6];
static char c1, c2;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> q;
    for (i32 i = 0; i < n; ++i) {
      cin >> c1 >> c2;
      switch (c1) {
        case 'B':
          switch (c2) {
            case 'G': a[i] = 0; break;
            case 'R': a[i] = 1; break;
            case 'Y': a[i] = 2;
          }
          break;
        case 'G': a[i] = 3 + (c2 == 'Y'); break;
        case 'R': a[i] = 5;
      }
      cout << a[i] << ' ';
    }
    cout << '\n';
    fill(t, t + 6, -1);
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < 6; ++j) p[i][j] = t[j], t[a[i]] = i;
    }
    fill(t, t + 6, -1);
    for (i32 i = n - 1; ~i; --i) {
      for (i32 j = 0; j < 6; ++j) p[i][j] = t[j], t[a[i]] = i;
    }
    while (q--) {
      cin >> l >> r;
    }
  }
}
