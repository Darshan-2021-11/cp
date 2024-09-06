#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'002, v[] = { -1, 1 }, MOD = 1e9 + 7;
static i32 TC, n, ps, ans;
static i64 t;
static map<i32, i64> m;
static map<i32, i64>::iterator it;
static char a[N], c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  while ((c = getchar()) != '\n') TC = TC * 10 + (c ^ '0');
  while (TC--) {
    n = !(ans = ps = 0);
    while ((c = getchar()) != '\n') a[n] = v[c ^ '0'], ++n;
    m[0] = 1;
    for (i32 i = 1; i <= n; ++i) {
      ps += a[i];
      if ((it = m.find(ps)) == m.end()) {
        m[ps] = i + 1;
        continue;
      }
      t = (*it).second;
      ans = (t * (n + 1 - i) + ans) % MOD;
      m[ps] = t + i + 1;
    }
    printf("%d\n", ans);
    m.clear();
  }
}
