#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, x, t;
set<u32> h = { 0 };
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n >> x;
    if (n % x) {
      cout << -1 << '\n';
      continue;
    }
    cout << x << ' ';
    for (u32 i = 2; i < n; ++i) {
      [[unlikely]] if (x == i) {
        for (t = 2;; ++t) if (!(n % (t * x))) break;
        x *= t;
        cout << x << ' ';
      }
      else cout << i << ' ';
    }
    cout << 1 << '\n';
  }
}
