#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, q, l, r, pa[N][26], pb[N][26], ans;
static char c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> q;
    for (i32 i = 1; i <= n; ++i) 
      for (i32 j = 0; j < 26; ++j)
        pa[i][j] = pb[i][j] = 0;
    for (i32 i = 1; i <= n; ++i) {
      cin >> c;
      for (i32 j = 0; j < 26; ++j) pa[i][j] = pa[i - 1][j];
      ++pa[i][c - 'a'];
    }
    for (i32 i = 1; i <= n; ++i) {
      cin >> c;
      for (i32 j = 0; j < 26; ++j) pb[i][j] = pb[i - 1][j];
      ++pb[i][c - 'a'];
    }
    for (i32 i = 0; i < q; ++i) {
      ans = 0;
      cin >> l >> r;
      for (i32 j = 0, x; j < 26; ++j) ans += abs((pa[r][j] - pa[l - 1][j]) - (pb[r][j] - pb[l - 1][j]));
      cout << (ans >> 1) << '\n';
    }
  }
}

