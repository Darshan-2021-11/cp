#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 200'000;
static i64 n, l[N], r[N], low, high;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (i32 i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    low += l[i], high += r[i];
  }
  if (low <= 0 && high >= 0) {
    cout << "Yes\n";
  } else {
    cout << "No";
    return 0;
  }
  i64 tmp = 0 - low;
  for (i32 i = 0; i < n; ++i) {
    if (tmp >= r[i] - l[i]) {
      cout << r[i] << ' ';
      tmp -= r[i] - l[i];
    } else if (tmp != 0) {
      cout << l[i] + tmp << ' ';
      tmp = 0;
    } else cout << l[i] << ' ';
  }
}

