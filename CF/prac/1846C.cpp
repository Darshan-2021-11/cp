#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 TC, n, t, u, d[100], pf[100], dn;
static i32 mn;
static void fnd(i64 num, i32 steps, i32 idx) {
  if (num == 0) { mn = min(steps, mn); return; }
  if (idx < 0 || pf[idx] < num || steps + 1 == mn) return;
  for (i32 i = 0; i < idx; ++i) {
    if (pf[i + 1] < num) continue;
    if (num < d[i]) break;
    fnd(num - d[i], steps + 1, i);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  t = 1; while (t <= static_cast<i64>(1e12)) d[dn++] = t, t <<= 1;
  u = 4, t = 6; while (t <= static_cast<i64>(1e12)) d[dn++] = t, t *= u++;
  sort(d, d + dn);
  for (i32 i = 0; i < dn; ++i) pf[i + 1] = pf[i] + d[i];
  while (TC--) {
    cin >> n;
    mn = __builtin_popcountll(n);
    fnd(n, 0, dn);
    cout << mn << '\n';
  }
}
