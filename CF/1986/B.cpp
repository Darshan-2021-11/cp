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

static i32 const dirn[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 }, };
static i32 TC, n, m, a[100][100], ti, tj, x;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> n >> m;
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < m; ++j) {
        x = INT_MIN;
        for (i32 k = 0; k < 4; ++k) {
          ti = i + dirn[k][0], tj = j + dirn[k][1];
          if (ti < 0 || ti >= n || tj < 0 || tj >= m) continue;
          x = max(x, a[ti][tj]);
        }
        a[i][j] = min(x, a[i][j]);
      }
    }
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < m; ++j) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}

