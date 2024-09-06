#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'001, logN = 19;
  i32 n, q;
  cin >> n >> q;
  i32 st[logN][N + 1], lgn = __lg(n) + 1;
  for (i32 i = 0; i < n; ++i) cin >> st[0][i];
  for (int i = 1; i <= lgn; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  for (i32 i = 0, l, r, lgt; i < q; ++i) {
    cin >> l >> r;
    --l, --r;
    lgt = __lg(r - l + 1);
    cout << min(st[lgt][l], st[lgt][r - (1 << lgt) + 1]) << '\n';
  }
}

