#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 T, n, l[3], r[3], lf, rg, mid, req, ans;
static vector<vector<i64>> p(3, vector<i64>(N));
static bool yes;

void calc_range() {
  l[0] = 1;
  lf = l[0], rg = ans = n + 1;
  while (lf <= rg) {
    mid = (lf + rg) >> 1;
    if (p[0][mid] - p[0][0] < req) lf = mid + 1;
    else ans = mid, rg = mid - 1;
  }
  if (ans >= n - 1) yes = false;
  r[0] = ans;
  l[1] = r[0] + 1;
  lf = l[1], rg = ans = n + 1;
  while (lf <= rg) {
    mid = (lf + rg) >> 1;
    if (p[1][mid] - p[1][r[0]] < req) lf = mid + 1;
    else ans = mid, rg = mid - 1;
  }
  if (ans >= n) yes = false;
  r[1] = ans;
  l[2] = r[1] + 1;
  r[2] = n;
  if (p[2][n] - p[2][r[1]] < req) yes = false;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    cin >> n;
    p[0][0] = p[1][0] = p[2][0] = 0;
    for (i32 i = 1; i <= n; ++i) cin >> p[0][i], p[0][i] += p[0][i - 1];
    for (i32 i = 1; i <= n; ++i) cin >> p[1][i], p[1][i] += p[1][i - 1];
    for (i32 i = 1; i <= n; ++i) cin >> p[2][i], p[2][i] += p[2][i - 1];
    req = (p[0][n] - 1) / 3 + 1;
    // abc
    yes = true;
    calc_range();
    if (yes) {
      cout << l[0] << ' ' << r[0] << ' ';
      cout << l[1] << ' ' << r[1] << ' ';
      cout << l[2] << ' ' << r[2] << '\n';
      continue;
    }
    // acb
    yes = true;
    swap(p[1], p[2]);
    calc_range();
    if (yes) {
      cout << l[0] << ' ' << r[0] << ' ';
      cout << l[2] << ' ' << r[2] << ' ';
      cout << l[1] << ' ' << r[1] << '\n';
      continue;
    }
    // bca
    yes = true;
    swap(p[0], p[2]);
    calc_range();
    if (yes) {
      cout << l[2] << ' ' << r[2] << ' ';
      cout << l[0] << ' ' << r[0] << ' ';
      cout << l[1] << ' ' << r[1] << '\n';
      continue;
    }
    // bac
    yes = true;
    swap(p[1], p[2]);
    calc_range();
    if (yes) {
      cout << l[1] << ' ' << r[1] << ' ';
      cout << l[0] << ' ' << r[0] << ' ';
      cout << l[2] << ' ' << r[2] << '\n';
      continue;
    }
    // cab
    yes = true;
    swap(p[0], p[2]);
    calc_range();
    if (yes) {
      cout << l[1] << ' ' << r[1] << ' ';
      cout << l[2] << ' ' << r[2] << ' ';
      cout << l[0] << ' ' << r[0] << '\n';
      continue;
    }
    // cba
    yes = true;
    swap(p[1], p[2]);
    calc_range();
    if (yes) {
      cout << l[2] << ' ' << r[2] << ' ';
      cout << l[1] << ' ' << r[1] << ' ';
      cout << l[0] << ' ' << r[0] << '\n';
      continue;
    }
    cout << -1 << '\n';
  }
}
