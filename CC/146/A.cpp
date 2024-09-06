#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 TC, a, b, c, m, yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> a >> b >> c >> m;
    yes = 0;
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; i + j <= m; ++j) {
        int k = m - i - j;
        if (a + i == b + j || a + i == c + k || b + j == c + k) { yes = 1; break; }
      }
    }
    cout << ( yes ? "YES" : "NO" ) << '\n';
  }
}

