#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;        using u32 = unsigned int;       using f32 = float;
using i64 = long long;  using u64 = unsigned long long; using f64 = double;
using i128 = __int128;  using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static struct range {
  i32 begin, end, profit;
} a[N];
static i64 dp[N << 1], mx;
static i32 i, l, r, t, n, mpn, mp[N << 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (i = 0, mpn = 1; i < n; ++i, mpn += 2) {
    cin >> a[i].begin >> a[i].end >> a[i].profit;
    mp[mpn] = a[i].begin, mp[mpn + 1] = a[i].end;
  }
  sort(mp, mp + mpn);
  mpn = unique(mp, mp + mpn) - mp;
  sort(a, a + n, [](const range x, const range y) {
      if (x.begin == y.begin)
        return x.end < y.end;
      return x.begin < y.begin;
      });
  for (i = 0, t = 1; i < n; ++i) {
    l = lower_bound(mp, mp + mpn, a[i].begin) - mp;
    r = lower_bound(mp, mp + mpn, a[i].end) - mp;
    while (t < l) dp[t] = max(dp[t - 1], dp[t]), ++t;
    dp[r] = max(dp[l - 1] + a[i].profit, dp[r]);
    mx = max(dp[r], mx);
  }
  cout << mx;
}
