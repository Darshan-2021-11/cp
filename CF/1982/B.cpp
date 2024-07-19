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

static i64 TC, x, k, y, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> x >> y >> k;
    while (x != 1) {
      t = (x / y + 1) * y - x;
      if (k >= t) k -= t, x += t;
      else { x += k, k = 0; break; }
      while (!(x % y)) x /= y;
    }
    if (x == 1) x += (k % (y - x));
    cout << x << '\n';
  }
}

