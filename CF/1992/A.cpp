#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i32 T, a, b, c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    i32 ans = 0;
    cin >> a >> b >> c;
    for (i32 i = 0; i <= 5; ++i) {
      for (i32 j = 0; j <= 5; ++j) {
        for (i32 k = 0; k <= 5; ++k) {
          if (i + j + k == 5) ans = max(ans, (a + i) * (b + j) * (c + k));
        }
      }
    }
    cout << ans << '\n';
  }
}

