#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 a[3], b[3], d[3], u, v;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  for (i32 i = 0; i < 3; ++i) cin >> a[i] >> b[i];
  u = abs(a[0] - a[1]), v = abs(b[0] - b[1]);
  d[0] = u * u + v * v;
  u = abs(a[0] - a[2]), v = abs(b[0] - b[2]);
  d[1] = u * u + v * v;
  u = abs(a[1] - a[2]), v = abs(b[1] - b[2]);
  d[2] = u * u + v * v;
  sort(d, d + 3);
  if (d[0] + d[1] == d[2]) cout << "Yes";
  else cout << "No";
}

