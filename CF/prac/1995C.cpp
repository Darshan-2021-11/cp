#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i64 TC, n, ans, r, p, ap, ac;
static i32 i, a[N], c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = p = 0;
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    for (i = 0; i < n && a[i] == 1; ++i);
    if (i == n) goto print;
    for (++i; i < n; ++i) {
      c = 0, ac = a[i];
      if (ac == 1) {
        ans = -1;
        break;
      }
      if (ac >= a[i - 1]) {
        r = 1;
        ap = a[i - 1];
        while (ap < ac) ap *= ap, ++r;
        ans += (p = p / r + (p % r != 0));
        continue;
      }
      while (ac < a[i - 1]) ac *= ac, ++c;
      ans += (p = c + c * p);
    }
print:
    cout << ans << '\n';
  }
}

