#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  i32 n, p, cnt = 1;
  bool p2 = false, nlz;
  cin >> n >> p;
  nlz = p != 0;
  for (i32 i = 1, t; i < n; ++i, p = t) {
    cin >> t;
    if (t) {
      cnt += nlz && p == 0;
      p2 |= t == 2;
    } else {
      if (p2 || (nlz && p != 0)) p2 = false, nlz = true;
      else nlz = false, ++cnt;
    }
  }
  cout << cnt << '\n';
}
