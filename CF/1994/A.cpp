#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 10;
static i64 TC, n, m, l, a[10][10];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> m;
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < m; ++j) cin >> a[i][j];
    }
    if (n == 1 && m == 1) { cout << -1 << '\n'; continue; }
    l = a[n - 1][m - 1];
    for (i32 i = 0; i < n; ++i) {
      cout << l << ' ';
      for (i32 j = 0; j < m - 1; ++j) cout << a[i][j] << ' ';
      l = a[i][m - 1];
      cout << '\n'; 
    }
  }
}

