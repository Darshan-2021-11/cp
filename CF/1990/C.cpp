#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i64 TC, ans, sum;
static i32 n, a[N], t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    map<i32, i32> mp;
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    ans = accumulate(a, a + n, i64{});
    sum = t = 0;
    for (i32 i = 0; i < n; ++i) {
      if (++mp[a[i]] > 1) t = max(t, a[i]);
      a[i] = t;
      sum += t;
    }
    mp.clear();
    ans += sum;
    sum = t = 0;
    for (i32 i = 0; i < n; ++i) {
      if (++mp[a[i]] > 1) t = max(t, a[i]);
      a[i] = t;
      sum += t;
    }
    ans += sum;
    for (i32 i = n - 1; ~i; --i) {
      if (!a[i]) break;
      sum -= a[i];
      ans += sum;
    }
    cout << ans << '\n';
  }
}

