#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 100'001, MOD = 998'244'353;
static i32 n, m, i, a[N], b[N], c[N], d[N], possible;
static i64 req;
i64 binpow(i64 x, i64 y) {
  x %= MOD;
  i64 res = 1;

  while (y > 0) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (i = 0; i < n; ++i) cin >> a[i];
  for (i = 0; i < n; ++i) cin >> b[i];
  cin >> m;
  for (i = 0; i < m; ++i) cin >> c[i];
  for (i = 0; i < m; ++i) cin >> d[i];
  possible = 1, req = 0, i = 0;
  for (i32 j = 0; j < m; ++j, ++i) {
    while (i < n && a[i] < c[j]) ++req, ++i;
    if (i == n || a[i] != c[j] || b[i] < d[j]) {
      possible = 0;
      break;
    }
    req += b[i] != d[j];
  }
  req += n - i;
  cout << (possible ? binpow(2, req) : 0) << '\n';
}

