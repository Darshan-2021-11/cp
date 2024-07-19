#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 500;
static i32 T, n, m;
static char a[N][N], b[N][N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (i32 i = 0; i < n; ++i) for (i32 j = 0; j < m; ++j) cin >> a[i][j];
    for (i32 i = 0; i < n; ++i) for (i32 j = 0; j < m; ++j) cin >> b[i][j];
  }
}

