#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i32 TC, n;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    if (!(n & 1)) {
      cout << -1 << '\n';
      continue;
    }
    for (i32 i = 0, a[2] = { 1, n }; i < n; ++i) {
      cout << a[i & 1] << ' ';
      a[1] -= i & 1;
      a[0] += !(i & 1);
    }
    cout << '\n';
  }
}

