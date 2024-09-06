#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i32 TC, l, r, x1, x2, res;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    l = 1, r = 999;
    while (l < r) {
      x1 = ((l << 1) + r) / 3;
      x2 = ((r << 1) + l) / 3;
      if (x1 == x2) ++x2;
      cout << "? " << x1 << ' ' << x2 << endl;
      cin >> res;
      if (res == x1 * x2) l = x2 + 1;
      else if (res == x1 * (x2 + 1)) l = x1 + 1, r = x2;
      else r = x1;
    }
    cout << "! " << l << endl;
  }
}
