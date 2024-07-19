#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 100'000;
static i64 T, n, i, bn, a[N], b[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    bn = 0;
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    b[bn++] = a[0];
    bool inc = a[1] > a[0];
    for (i = 1; i < n; ++i) {
      if ((a[i] > a[i - 1]) == inc) continue;
      b[bn++] = a[i - 1];
      inc = !inc;
    }
    b[bn++] = a[n - 1];
    cout << bn << '\n';
    for (i = 0; i < bn; ++i) cout << b[i] << ' ';
    cout << '\n';
  }
}

