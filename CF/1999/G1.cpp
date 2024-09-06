#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 TC, l, r, x, y, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    l = 2, r = 999;
    while (l <= r) {
      x = (l + r + 1) >> 1;
      cout << '?' << ' ' << 1 << ' ' << x << endl;
      cin >> y;
      if (y > x) r = x - 1;
      else l = x + 1, ans = x;
    }
    cout << '!' << ' ' << l << endl;
  }
}

