#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i32 TC, x, y, k;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> x >> y >> k;
    switch (k % 4) {
      case 1:
        cout << x << ' ' << y << '\n';
        break;
      case 2:
        cout << x - 1 << ' ' << y << '\n';
        cout << x + 1 << ' ' << y << '\n';
        break;
      case 3:
        cout << -1 + x << ' ' << -1 + y << '\n';
        cout << 5 + x << ' ' << -1 + y << '\n';
        cout << -4 + x << ' ' << 2 + y << '\n';
    }
    for (i32 i = 1; i <= (k >> 2); ++i) {
      cout << x - 2 * i << ' ' << y << '\n';
      cout << x + 2 * i << ' ' << y << '\n';
      cout << x << ' ' << y - 2 * i << '\n';
      cout << x << ' ' << y + 2 * i << '\n';
    }
  }
}

